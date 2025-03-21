#ifndef RFM_H
#define RFM_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rfm_packet_s {
#define RFM_PACKET_LENGTH 16
#define RFM_TX_TIMEOUT    100000

    // Data Buffer
    union {
        uint8_t buffer[RFM_PACKET_LENGTH];

        struct {
            uint32_t device_number;
            uint32_t msg_number;
            int8_t   power;
            uint16_t battery;
            int16_t  temperature;
            bool     bad_reboot;
        };
    } data;

    // Usefull info
    uint8_t flags;
    bool    crc_ok;
    int8_t  snr;
    int16_t rssi;

    // Basic message organization
    enum {
        RFM_PACKET_DEV_NUM_0 = 0,
        RFM_PACKET_DEV_NUM_1,
        RFM_PACKET_DEV_NUM_2,
        RFM_PACKET_DEV_NUM_3,
        RFM_PACKET_MSG_NUM_0,
        RFM_PACKET_MSG_NUM_1,
        RFM_PACKET_MSG_NUM_2,
        RFM_PACKET_MSG_NUM_3,
        RFM_PACKET_POWER,
        RFM_PACKET_BATTERY_0,
        RFM_PACKET_BATTERY_1,
        RFM_PACKET_TEMP_0,
        RFM_PACKET_TEMP_1
    } packet_data_e;

} rfm_packet_t;

rfm_packet_t packet = {
    .crc_ok = true,
};

void rfm_init(void) {
}
void rfm_reset(void) {
}
void rfm_end(void) {
}
void rfm_calibrate_crystal(void) {
}
void rfm_config_for_lora(uint8_t BW, uint8_t CR, uint8_t SF, bool crc_turn_on,
                         int8_t power) {
    (void)BW;
    (void)CR;
    (void)SF;
    (void)crc_turn_on;
    (void)power;
}
void rfm_config_for_gfsk(void) {
}
void rfm_set_power(int8_t power, uint8_t ramp_time) {
    (void)power;
    (void)ramp_time;
}
void rfm_get_stats(void) {
}
void rfm_reset_stats(void) {
}
uint8_t rfm_get_version(void) {
    return 1;
}

void rfm_start_listening(void) {
}
void rfm_get_packets(void) {
}
rfm_packet_t* rfm_get_next_packet(void) {
    return &packet;
}
uint8_t rfm_get_num_packets(void) {
    return 0;
}

bool rfm_transmit_packet(rfm_packet_t packet) {
    (void)packet;
    return true;
}
void rfm_set_tx_continuous(void) {
}
void rfm_clear_tx_continuous(void) {
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif // RFM_H