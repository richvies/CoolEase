/**
 ******************************************************************************
 * @file    hub.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Hub Source File
 *
 ******************************************************************************
 */

#include "hub/hub.h"

#include <string.h>

#include "libopencm3/cm3/nvic.h"
#include "libopencm3/cm3/scb.h"
#include "libopencm3/stm32/rtc.h"
#include "libopencm3/stm32/syscfg.h"

#include "common/aes.h"
#include "common/battery.h"
#include "common/log.h"
#include "common/memory.h"
#include "common/printf.h"
#include "common/reset.h"
#include "common/rfm.h"
#include "common/timers.h"
#include "config/board_defs.h"

#include "hub/cusb.h"
#include "hub/sim.h"

#define VERSION                   101
#define HUB_CHECK_TIME_S          60
#define HUB_LOG_TIME_S            3600
#define NET_SLEEP_TIME_DEFAULT_MS 120000
#define HUB_PLUGGED_IN_VALUE      0x2468
#define HUB_PLUGGED_OUT_VALUE     0x1357

#define NET_LOG                                                                \
    log_printf("NET: ");                                                       \
    log_printf

// TODO
// Http post with ssl, logging

/** @addtogroup HUB_FILE
 * @{
 */

typedef enum {
    NET_0 = 0,
    NET_UPLOAD_FIRST_PACKET,
    NET_INIT,
    NET_HARD_RESET,
    NET_REGISTERING,
    NET_REGISTERED,
    NET_CONNECTING,
    NET_CONNECTED,
    NET_RUNNING,
    NET_CHECK_CONNECTION,
    NET_HTTPINIT,
    NET_HTTPPOST,
    NET_HTTPREADY,
    NET_HTTP_DONE,
    NET_ASSEMBLE_PACKET,
    NET_POST,
    NET_SLEEP_START,
    NET_SLEEP_TRY_POST_AGAIN,
    NET_GO_TO_SLEEP,
    NET_SLEEP,
    NET_PARSE_RESPONSE,
    NET_SEND_ERROR_SMS,
    NET_ERROR,
    NET_NUM_STATES,
} net_state_t;

/** @addtogroup HUB_INT
 * @{
 */

static bool hub_plugged_in;

static uint32_t upgrade_to_version;

static sensor_t sensors[MAX_SENSORS] = {0};
static uint8_t  num_sensors;

static char     net_buf[1536];
static uint16_t net_buf_idx = 0;

static bool     log_upload_pending;
static bool     pwr_upload_pending;
static bool     check_upload_pending;
static bool     log_appended;
static bool     pwr_appended;
static bool     check_appended;
static uint32_t log_counter;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void deinit(void);

static void test(void);
static void hub(void);

static uint32_t get_timestamp(void);
static void     check_for_packets(void);

static void net_task(void);
static bool upload_pending(void);
static void clear_upload_pending(void);
static void parse_net_response(void);

static bool    check_pending(void);
static uint8_t temps_pending(void);
static bool    log_pending(void);
static bool    pwr_pending(void);
static void    append_check(void);
static void    append_temp(void);
static void    append_log(void);
static void    append_pwr(void);

static void update_sensor_list(const char* list_start,
                               uint32_t    sensor_list_len);

static void     net_buf_clear(void);
static uint32_t net_buf_append_printf(const char* format, ...);
static void     _putchar_buffer(char character);

/** @} */

/** @addtogroup HUB_API
 * @{
 */

//
int main(void) {
    init();

    // Check if first time running
    if (app_info->init_key != APP_INIT_KEY) {
        log_printf("APP: First Run\n");

        serial_printf(".App: v%u\n", VERSION);
        serial_printf(".Boot: v%u\n", shared_info->boot_version);
        serial_printf(".Dev ID: %u\n", app_info->dev_id);
        serial_printf(".PWD: %s\n", app_info->pwd);
        serial_printf(".AES: ");
        for (uint8_t i = 0; i < 16; i++) {
            serial_printf("%2x ", app_info->aes_key[i]);
        }
        serial_printf("\n");

        mem_eeprom_write_word_ptr(&shared_info->app_curr_version, VERSION);
        mem_eeprom_write_word_ptr(&shared_info->app_ok_key, SHARED_APP_OK_KEY);

        mem_eeprom_write_word_ptr(&app_info->init_key, APP_INIT_KEY);

        // Sensor init - IDs, active or not,

        // Reset to signal OK to bootloader
        timers_pet_dogs();
        timers_delay_milliseconds(1000);
        deinit();
        scb_reset_system();
    }

    log_printf("Hub Start\n");

    test();

    hub();

    for (;;) {
        log_printf("Hub Loop\n\n");
        timers_delay_milliseconds(1000);
    }

    return 0;
}

void set_gpio_for_standby(void) {
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);

    // LED
    gpio_mode_setup(LED_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, LED);

    // Serial Print
    // FTDI not connected
    usart_disable(SPF_USART);
    rcc_periph_clock_disable(SPF_USART_RCC);
    gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    SPF_USART_TX);
    gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    SPF_USART_RX);
    // FTDI Connected
    // gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP,
    // SPF_USART_TX); gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_OUTPUT,
    // GPIO_PUPD_NONE,  SPF_USART_RX);
    // gpio_set_output_options(SPF_USART_RX_PORT, GPIO_OTYPE_OD,
    // GPIO_OSPEED_2MHZ, SPF_USART_RX); gpio_set(SPF_USART_RX_PORT,
    // SPF_USART_RX);

    // Batt Sense
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    BATT_SENS);
    gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);

    // RFM
    // SPI
    gpio_mode_setup(RFM_SPI_MISO_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    RFM_SPI_MISO);

    gpio_mode_setup(RFM_SPI_SCK_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN,
                    RFM_SPI_SCK);
    gpio_mode_setup(RFM_SPI_MOSI_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN,
                    RFM_SPI_MOSI);

    gpio_mode_setup(RFM_SPI_NSS_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP,
                    RFM_SPI_NSS);
    gpio_mode_setup(RFM_RESET_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP,
                    RFM_RESET);

    // DIO
    // Input or analog, seems to make no difference
    gpio_mode_setup(RFM_IO_0_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_0);
    gpio_mode_setup(RFM_IO_1_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_1);
    gpio_mode_setup(RFM_IO_2_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_2);
    gpio_mode_setup(RFM_IO_3_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_3);
    gpio_mode_setup(RFM_IO_4_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_4);
    gpio_mode_setup(RFM_IO_5_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_5);

    // SIM
    gpio_mode_setup(SIM_USART_TX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_PULLUP,
                    SIM_USART_TX);
    gpio_mode_setup(SIM_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_PULLUP,
                    SIM_USART_RX);
}

//
sensor_t* get_sensor_by_id(uint32_t dev_id) {
    sensor_t* sensor = NULL;

    for (uint8_t i = 0; i < MAX_SENSORS; i++) {
        if ((sensors[i].active) && (sensors[i].dev_id == dev_id)) {
            sensor = &sensors[i];
            break;
        }
    }
    return sensor;
}

void clean_sensors(void) {
    num_sensors = 0;

    for (uint8_t i = 0; i < MAX_SENSORS; i++) {
        sensors[i].active = false;
    }
}

void add_sensor(uint32_t dev_id) {
    sensor_t* sensor = NULL;

    // if not already in list
    if (get_sensor_by_id(dev_id) == NULL) {
        // Add sensor to first available slot
        for (uint8_t i = 0; i < MAX_SENSORS; i++) {
            sensor = &sensors[i];

            if (sensor->active == false) {
                memset(&sensors[i], 0, sizeof(sensors[0]));

                sensor->active = true;
                sensor->dev_id = dev_id;

                ++num_sensors;

                break;
            }
        }
    }
}

void rem_sensor(uint32_t dev_id) {
    sensor_t* sensor = get_sensor_by_id(dev_id);
    if (sensor != NULL) {
        sensor->active = false;
        --num_sensors;
    }
}

void print_sensors(void) {
    uint8_t   count = 0;
    sensor_t* sensor = NULL;

    serial_printf("HUB: %u sensors\n", num_sensors);

    for (uint8_t i = 0; i < MAX_SENSORS; i++) {
        sensor = &sensors[i];

        if (sensor->active == false) {
            continue;
        } else {
            serial_printf(".%3u", i);
            serial_printf(" id  : %u\n", sensor->dev_id);
            serial_printf(".temp: %i", sensor->temperature);
            serial_printf(" batt: %u", sensor->battery);
            serial_printf(" pwr : %i", sensor->power);
            serial_printf(" rssi: %i\n", sensor->rssi);
            count++;
        }
    }
    serial_printf(".%s expected: %u count: %u\n",
                  num_sensors == count ? "OK" : "Error", num_sensors, count);
}

static void update_sensor_list(const char* list_start, const uint32_t len) {
    uint32_t  i = 0;
    uint32_t  list[MAX_SENSORS];
    sensor_t* sensor = NULL;

    serial_printf("HUB: Update sensors\n");
    // serial_printf(".list %s\n", list_start);

    // IDs ascii to int
    while ((i < len) && (*(list_start++) == ',')) {
        list[i] = _atoi((const char**)&list_start);
        ++i;
    }

    // Remove any not on list
    for (i = 0; i < MAX_SENSORS; i++) {
        sensor = &sensors[i];

        if ((sensor == NULL) || (sensor->active == false)) {
            continue;
        } else {
            bool found = false;

            for (uint32_t j = 0; j < len; j++) {
                if (list[j] == sensor->dev_id) {
                    found = true;
                    break;
                }
            }

            if (found == false) {
                rem_sensor(sensor->dev_id);
            }
        }
    }

    // Add new
    for (i = 0; i < len; i++) {
        add_sensor(list[i]);
    }

    // print_sensors();
}

/** @} */

/** @addtogroup HUB_INT
 * @{
 */

//
static void init(void) {
    clock_setup_hsi_16mhz();
    timers_lptim_init();
    log_init();
    aes_init(app_info->aes_key);
    batt_init();

    flash_led(100, 1);
}

static void deinit(void) {
    // cusb_end();
    batt_end();
    SYSCFG_CFGR3 &= ~SYSCFG_CFGR3_EN_VREFINT;
    log_end();
    timers_lptim_end();
    rcc_periph_clock_disable(RCC_GPIOA);
    rcc_periph_clock_disable(RCC_GPIOB);
    clock_setup_msi_2mhz();
}

static void test(void) {
    // Test bootloader watchdog handling
    // serial_printf(".Testing 000 Do Nothing\n");
    // while (1)
    // {
    // 	timers_pet_dogs();
    // 	timers_delay_milliseconds(1000);
    // }

    // test_bkp_reg();
    // test_revceiver_basic();
    // test_sim_timestamp();
    // test_sim_send_sms();
    // test_sim_init();
    // test_sim_send_sms();
    // test_sim_serial_passthrough();
    // test_sim_get_request();
    // test_sim_get_request_version();
    // test_sim_post();

    // test_sim_get_request();
}

static void hub(void) {
    /**/
    // Register with cloud

    // Power checking
    batt_enable_interrupt();

    // USB checking

    // Sensors to listen for
    clean_sensors();
    print_sensors();

    // Start listening on rfm
    rfm_init();
    rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5,
                        RFM_SPREADING_FACTOR_128CPS, true, 0);
    rfm_start_listening();

    // Todo
    // Get timestamp from sim
    uint32_t timestamp = get_timestamp();
    serial_printf("got timestamp %d", timestamp);

    // Init rtc, one hour wakeup flag for logging & checking software
    timers_rtc_init();
    timers_set_wakeup_time(HUB_CHECK_TIME_S);
    timers_disable_wut_interrupt();

    // Assume plugged in at first
    hub_plugged_in = true;

    // Initial upload
    check_upload_pending = true;
    pwr_upload_pending = true;
    log_upload_pending = true;

    for (;;) {
        // Check for packets
        check_for_packets();

        // Keep record of id, num packets, temperature, battery for each sensor
        // Timestamp packets

        if (batt_is_ready()) {
            // Check if hub plugged in or out since last check
            // Notify cloud if it has
            if (hub_plugged_in ^ batt_is_plugged_in()) {
                log_printf("PWR: plugged %s\n", hub_plugged_in ? "out" : "in");
                pwr_upload_pending = true;
            }
            hub_plugged_in = batt_is_plugged_in();
        }

        // Check time?
        if (RTC_ISR & RTC_ISR_WUTF) {
            timers_clear_wakeup_flag();
            check_upload_pending = true;
            log_counter++;

            if (log_counter >= HUB_LOG_TIME_S / HUB_CHECK_TIME_S) {
                log_counter = 0;
                log_upload_pending = true;
                pwr_upload_pending = true;
            }
        }

        // Deal with modem and uploading to azure
        net_task();

        // Start upgrade if signaled by cloud
        if (upgrade_to_version != 0) {
            if (hub_plugged_in) {
                log_printf("UPG: Start\n");
                mem_eeprom_write_word_ptr(&shared_info->app_next_version,
                                          upgrade_to_version);
                mem_eeprom_write_word_ptr(&shared_info->upg_pending,
                                          SHARED_UPGRADE_PENDING_KEY);

                timers_pet_dogs();
                timers_delay_milliseconds(500);
                deinit();
                scb_reset_system();
            } else {
                log_printf("UPG: Not plugged in\n");
            }

            upgrade_to_version = 0;
        }

        timers_pet_dogs();

        timers_delay_milliseconds(1);

        // PRINT_OK();
    }
}

//
static uint32_t get_timestamp(void) {
    uint32_t stamp = 0;

    return stamp;
}

static void check_for_packets(void) {
    if (rfm_get_num_packets() > 0) {
        log_printf("RFM: #RX %u\n", rfm_get_num_packets());

        while (rfm_get_num_packets()) {
            // Get packet, decrypt and organise
            rfm_packet_t* packet = rfm_get_next_packet();
            aes_ecb_decrypt(packet->data.buffer);

            // Get sensor from device number
            sensor_t* sensor = get_sensor_by_id(packet->data.device_number);

            // Skip if wrong device number
            if (sensor == NULL) {
                log_printf(".Bad ID %u\n", packet->data.device_number);
                continue;
            } else {
                sensor->power = packet->data.power;
                sensor->battery = packet->data.battery;
                sensor->temperature = packet->data.temperature;
                sensor->msg_num++;
                sensor->msg_pend = true;
                sensor->msg_appended = false;
                sensor->rssi = packet->rssi;
            }

            // Print packet details
            serial_printf(".Packet\n.//////////\n");
            serial_printf(".Device ID: %08u\n", packet->data.device_number);
            serial_printf(".Packet RSSI: %i dbm\n", packet->rssi);
            serial_printf(".Packet SNR: %i dB\n", packet->snr);
            serial_printf(".Power: %i\n", packet->data.power);
            serial_printf(".Battery: %uV\n", packet->data.battery);
            serial_printf(".Temperature: %i\n", packet->data.temperature);
            serial_printf(".Message Number: %i\n", packet->data.msg_number);
            serial_printf(".//////////\n");
        }
    }
}

static void net_task(void) {
    static net_state_t net_state = NET_0;
    static net_state_t net_next_state;
    static net_state_t net_fallback_state;

    static uint32_t net_sleep_start;
    static uint32_t net_sleep_time_ms = NET_SLEEP_TIME_DEFAULT_MS;
    static bool     net_sleep_expired;

    net_sleep_expired =
        (uint32_t)(timers_millis() - net_sleep_start) > net_sleep_time_ms;

    sim800.state = SIM_ERROR;

    switch (net_state) {
    // Upload inital message
    case NET_0:
        NET_LOG("FIRST UPLOAD\n");
        net_next_state = NET_UPLOAD_FIRST_PACKET;

        sim800.state = SIM_SUCCESS;

        break;

    case NET_UPLOAD_FIRST_PACKET:
        net_next_state = NET_REGISTERING;
        net_fallback_state = NET_UPLOAD_FIRST_PACKET;

        sim800.state = sim_init();
        break;

    case NET_INIT:

        net_next_state = NET_REGISTERING;
        net_fallback_state = NET_INIT;

        sim800.state = sim_init();

        break;

    case NET_REGISTERING:
        net_next_state = NET_REGISTERED;
        net_fallback_state = NET_INIT;

        sim800.state = sim_register_to_network();
        break;

    case NET_REGISTERED:
        NET_LOG("Registered\n");
        net_next_state = NET_CONNECTING;
        net_fallback_state = NET_INIT;

        sim800.state = SIM_SUCCESS;
        break;

    case NET_CONNECTING:
        net_next_state = NET_CONNECTED;
        net_fallback_state = NET_REGISTERING;

        sim800.state = sim_open_bearer("data.rewicom.net", "", "");
        break;

    case NET_CONNECTED:
        NET_LOG("Connected\n");

        net_next_state = NET_RUNNING;
        net_fallback_state = NET_CONNECTING;
        sim800.state = SIM_SUCCESS;
        break;

    case NET_RUNNING:
        net_next_state = NET_RUNNING;
        net_fallback_state = NET_CONNECTING;
        sim800.state = SIM_BUSY;

        if (upload_pending()) {
            NET_LOG("Upload\n");
            net_next_state = NET_CHECK_CONNECTION;
            sim800.state = SIM_SUCCESS;
        } else if (false == hub_plugged_in) {
            net_sleep_time_ms = NET_SLEEP_TIME_DEFAULT_MS;
            net_next_state = NET_GO_TO_SLEEP;
            sim800.state = SIM_SUCCESS;
        }
        break;

    case NET_CHECK_CONNECTION:
        sim800.state = sim_is_connected();
        net_fallback_state = NET_CONNECTING;
        net_next_state = NET_ASSEMBLE_PACKET;

        break;

    case NET_ASSEMBLE_PACKET:
        net_next_state = NET_HTTPPOST;
        net_fallback_state = NET_CONNECTED;
        sim800.state = SIM_SUCCESS;

        net_buf_clear();

        net_buf_append_printf("pwd=%s"
                              "&id=%u",
                              app_info->pwd, app_info->dev_id);

        serial_printf(".check\n");
        append_check();

        serial_printf(".get sensors\n");
        net_buf_append_printf("&sensors=get");

        if (pwr_pending()) {
            serial_printf(".Pwr\n");
            append_pwr();
        }

        if (temps_pending()) {
            serial_printf(".Temps: %u\n", temps_pending());
            append_temp();
        }

        if (log_pending()) {
            serial_printf(".Log\n");
            append_log();
            log_appended = true;
        }

        net_buf_append_printf("\0\0");

        serial_printf("//////////\nMSG %u: %s\n//////////\n", strlen(net_buf),
                      net_buf);
        timers_delay_milliseconds(1000);
        break;

    case NET_HTTPPOST:
        net_next_state = NET_HTTP_DONE;
        net_fallback_state = NET_RUNNING;

        upgrade_to_version = 0;

        sim800.state = sim_http_post_str(
            "http://rickceas.azurewebsites.net/CE/hub.php", net_buf, false, 3);
        break;

    case NET_HTTP_DONE:
        net_next_state = NET_RUNNING;
        net_fallback_state = NET_RUNNING;
        sim800.state = SIM_SUCCESS;

        serial_printf("HTTP: %u %u\n", sim800.http.status_code,
                      sim800.http.response_size);
        NET_LOG("Parse response\n");
        parse_net_response();
        clear_upload_pending();
        break;

    case NET_SLEEP_START:
        net_next_state = NET_GO_TO_SLEEP;
        sim800.state = SIM_SUCCESS;

        // Start timer
        net_sleep_start = timers_millis();
        break;

    case NET_GO_TO_SLEEP:
        net_next_state = NET_SLEEP;
        net_fallback_state = NET_INIT;

        sim800.state = sim_sleep();
        break;

    case NET_SLEEP:
        net_next_state = NET_SLEEP;
        net_fallback_state = NET_SLEEP;

        sim800.state = SIM_SUCCESS;

        if (hub_plugged_in || (net_sleep_expired && upload_pending())) {
            net_next_state = NET_INIT;
        }
        // Sim sometimes wakes up randomly, NET_INIT will put back to sleep
        else if (sim_printf_and_check_response(100, "OK", "AT\r")) {
            net_next_state = NET_GO_TO_SLEEP;
        }
        break;

    case NET_ERROR:
        NET_LOG("ERROR State\n");
        net_next_state = NET_INIT;
        sim800.state = SIM_SUCCESS;
        break;

    default:
        NET_LOG("DEFAULT State\n");
        net_next_state = NET_INIT;
        sim800.state = SIM_SUCCESS;
        break;
    }

    if (sim800.state == SIM_SUCCESS) {
        net_state = net_next_state;
    } else if (sim800.state == SIM_ERROR || sim800.state == SIM_TIMEOUT) {
        NET_LOG("SIM ERR %u fb %u\n", net_state, net_fallback_state);
        net_state = net_fallback_state;
    }
}

static bool upload_pending(void) {
    return (check_pending() || temps_pending() || log_pending() ||
            pwr_pending());
}

static void clear_upload_pending(void) {
    if (check_upload_pending && check_appended) {
        check_upload_pending = false;
        check_appended = false;
    }

    for (uint8_t i = 0; i < num_sensors; i++) {
        sensor_t* sensor = &sensors[i];
        if (sensor->msg_pend && sensor->msg_appended) {
            sensor->msg_pend = false;
            sensor->msg_appended = false;
        }
    }

    if (log_upload_pending && log_appended) {
        log_upload_pending = false;
        log_appended = false;
    }

    if (pwr_upload_pending && pwr_appended) {
        pwr_upload_pending = false;
        pwr_appended = false;
    }
}

static void parse_net_response(void) {
    uint32_t sensor_list_len = 0;
    uint32_t num_bytes = 0;

    char* str = NULL;

    net_buf_clear();

    if (sim800.http.response_size > sizeof(net_buf) - 1) {
        NET_LOG(".ERR resp too big %u!\n", sim800.http.response_size);
        return;
    }

    if (sim800.http.response_size) {
        num_bytes = sim_http_read_response(0, sim800.http.response_size,
                                           (uint8_t*)net_buf);

        net_buf[num_bytes] = '\0';

        // Print header
        serial_printf(".num bytes: %u\n.header: %s\n", num_bytes, net_buf);

        // Version
        str = strstr(net_buf, "version=");
        if (str != NULL) {
            str += strlen("verison=");
            upgrade_to_version = _atoi((const char**)&str);
            serial_printf(".Upgrade to v%u\n", upgrade_to_version);
        }

        // Sensor list
        str = strstr(net_buf, "sensors=");
        if (str != NULL) {
            str += strlen("sensors=");
            sensor_list_len = _atoi((const char**)&str);

            serial_printf(".List len: %u\n", sensor_list_len);

            if (sensor_list_len > MAX_SENSORS) {
                NET_LOG(".ERR sens list too long %u, max is %u\n",
                        sensor_list_len, MAX_SENSORS);
            } else {
                update_sensor_list(str, sensor_list_len);
            }
        }
    }
}

///
static bool check_pending(void) {
    return check_upload_pending;
}

static uint8_t temps_pending(void) {
    uint8_t res = 0;
    for (uint8_t i = 0; i < num_sensors; i++) {
        if (sensors[i].msg_pend) {
            ++res;
        }
    }

    return res;
}

static bool log_pending(void) {
    return log_upload_pending;
}

static bool pwr_pending(void) {
    return pwr_upload_pending;
}

///
static void append_check(void) {
    net_buf_append_printf("&currver=%u&version=get", VERSION);
    check_appended = true;
}

static void append_temp(void) {
    uint8_t num_pending = temps_pending();
    net_buf_append_printf("&num_temp=%u", num_pending);

    if (num_pending) {
        uint16_t j = 0;
        for (uint16_t i = 0; i < MAX_SENSORS; i++) {
            sensor_t* sensor = &sensors[i];

            if (sensor->msg_pend) {
                net_buf_append_printf("&id%u=%u", j, sensor->dev_id);
                net_buf_append_printf("&temp%u=%i", j, sensor->temperature);
                net_buf_append_printf("&batt%u=%u", j, sensor->battery);
                net_buf_append_printf("&rssi%u=%i", j, sensor->rssi);

                sensor->msg_appended = true;

                ++j;
            }
        }
    }
}

static void append_log(void) {
    net_buf_append_printf("&log=\n-----LOG START------\n");

    log_read_reset();
    for (uint16_t i = 0; i < log_size(); i++) {
        char c = log_read();
        if (c == '\0') {
            c = ' ';
        }
        net_buf_append_printf("%c", c);
    }

    net_buf_append_printf("\n-----LOG END------\n");
    log_appended = true;
}

static void append_pwr(void) {
    net_buf_append_printf("&hub_batt=%u"
                          "&hub_pwr=%u"
                          "&hub_plugged_in=%u",
                          batt_get_pwr_voltage(), batt_get_batt_voltage(),
                          hub_plugged_in ? HUB_PLUGGED_IN_VALUE
                                         : HUB_PLUGGED_OUT_VALUE);
    pwr_appended = true;
}

///
static void net_buf_clear(void) {
    memset(net_buf, '\0', sizeof(net_buf));
    net_buf_idx = 0;
}

static uint32_t net_buf_append_printf(const char* format, ...) {
    va_list va;
    va_start(va, format);
    uint32_t res = fnprintf(_putchar_buffer, format, va);
    va_end(va);

    return res;
}

static void _putchar_buffer(char character) {
    net_buf[net_buf_idx++] = character;
}

/** @} */

/** @} */
