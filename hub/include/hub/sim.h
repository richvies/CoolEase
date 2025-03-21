/**
 ******************************************************************************
 * @file    sim.h
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   SIM800 Module Interface Header File
 *
 * @defgroup hub Hub
 * @{
 *   @defgroup sim_api SIM800 Interface
 *   @brief    Cellular modem (SIM800) communication and control interface
 * @}
 ******************************************************************************
 */

#ifndef SIM_H
#define SIM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup hub
 * @{
 */

/** @addtogroup sim_api
 * @{
 */

/**
 * @brief SIM800 operation state enumeration
 */
typedef enum sim_state {
    SIM_BUSY = 0, /**< Operation in progress */
    SIM_SUCCESS,  /**< Operation completed successfully */
    SIM_TIMEOUT,  /**< Operation timed out */
    SIM_ERROR     /**< Operation failed with error */
} sim_state_t;

/**
 * @brief SIM800 functionality mode enumeration
 */
typedef enum sim_function {
    FUNC_MIN = 0,   /**< Minimum functionality */
    FUNC_FULL = 1,  /**< Full functionality */
    FUNC_NO_RF = 4, /**< Disable RF circuit */
    FUNC_OFF,       /**< Power off */
    FUNC_RESET,     /**< Reset device */
    FUNC_SLEEP      /**< Sleep mode */
} sim_function_t;

/**
 * @brief Network registration status enumeration
 */
typedef enum registration_status {
    REG_NONE = 0,  /**< Not registered */
    REG_HOME,      /**< Registered to home network */
    REG_SEARCHING, /**< Searching for network */
    REG_DENIED,    /**< Registration denied */
    REG_UNKNOWN,   /**< Unknown status */
    REG_ROAMING    /**< Registered with roaming */
} registration_status_t;

/**
 * @brief HTTP operation state enumeration
 */
typedef enum http_state {
    HTTP_TERM = 0, /**< HTTP terminated */
    HTTP_INIT,     /**< HTTP initialized */
    HTTP_ACTION,   /**< HTTP action in progress */
    HTTP_DONE,     /**< HTTP action completed */
    HTTP_ERROR     /**< HTTP error occurred */
} http_state_t;

/**
 * @brief SIM800 device state structure
 */
typedef struct sim800_s {
    sim_state_t           state;      /**< Current operation state */
    sim_function_t        func;       /**< Current functionality mode */
    registration_status_t reg_status; /**< Network registration status */

    struct http_params {
        http_state_t state;         /**< HTTP operation state */
        uint32_t     status_code;   /**< HTTP response status code */
        uint32_t     response_size; /**< HTTP response size in bytes */
    } http;                         /**< HTTP parameters */
} sim800_t;

extern sim800_t sim800; /**< Global SIM800 state */

/**
 * @brief Print formatted string to SIM800
 * @param format Format string
 * @param ... Variable arguments
 * @return None
 */
void sim_printf(const char* format, ...);

/**
 * @brief Print to SIM800 and wait for expected response or timeout
 * @param timeout_ms Timeout in milliseconds
 * @param expected_response Expected response string
 * @param format Format string
 * @param ... Variable arguments
 * @return true if expected response received, false otherwise
 */
bool sim_printf_and_check_response(uint32_t    timeout_ms,
                                   const char* expected_response,
                                   const char* format, ...);

/**
 * @brief Enable pass-through mode for SIM800 serial communication
 * @return None
 */
void sim_serial_pass_through(void);

/**
 * @brief Print SIM800 state
 * @param res State to print
 * @return None
 */
void sim_print_state(sim_state_t res);

/**
 * @brief Check if data is available from SIM800
 * @return true if data available, false otherwise
 */
bool sim_available(void);

/**
 * @brief Read a character from SIM800
 * @return Character read
 */
char sim_read(void);

// Setup & Config

/**
 * @brief Initialize SIM800 module
 * @details Enables MCU USART, resets SIM800 into minimum functionality mode
 *          and disables command echo
 * @return Operation result
 */
sim_state_t sim_init(void);

/**
 * @brief Terminate SIM800 operations
 * @details Enters sleep mode and disables MCU USART
 * @return Operation result
 */
sim_state_t sim_end(void);

/**
 * @brief Put SIM800 into sleep mode
 * @return Operation result
 */
sim_state_t sim_sleep(void);

/**
 * @brief Register SIM800 to cellular network
 * @return Operation result
 */
sim_state_t sim_register_to_network(void);

// Device information

/**
 * @brief Print SIM800 capabilities
 * @return None
 */
void sim_print_capabilities(void);

// Network Configuration

/**
 * @brief Get network timestamp
 * @return Pointer to timestamp data
 */
uint8_t* sim_get_timestamp(void);

/**
 * @brief Open GPRS bearer connection
 * @param apn_str Access Point Name
 * @param user_str Username
 * @param pwd_str Password
 * @return Operation result
 */
sim_state_t sim_open_bearer(char* apn_str, char* user_str, char* pwd_str);

/**
 * @brief Close GPRS bearer connection
 * @return Operation result
 */
sim_state_t sim_close_bearer(void);

/**
 * @brief Check if connected to network
 * @return Operation result
 */
sim_state_t sim_is_connected(void);

/**
 * @brief Initialize HTTP service
 * @param url_str URL string
 * @param ssl Enable SSL/TLS
 * @return Operation result
 */
sim_state_t sim_http_init(const char* url_str, bool ssl);

/**
 * @brief Terminate HTTP service
 * @return Operation result
 */
sim_state_t sim_http_term(void);

/**
 * @brief Perform HTTP GET request
 * @param url_str URL string
 * @param ssl Enable SSL/TLS
 * @param num_tries Number of retry attempts
 * @return Operation result
 */
sim_state_t sim_http_get(const char* url_str, bool ssl, uint8_t num_tries);

/**
 * @brief Perform HTTP POST with string data
 * @param url_str URL string
 * @param msg_str Message string to post
 * @param ssl Enable SSL/TLS
 * @param num_tries Number of retry attempts
 * @return Operation result
 */
sim_state_t sim_http_post_str(const char* url_str, const char* msg_str,
                              bool ssl, uint8_t num_tries);

/**
 * @brief Initialize HTTP POST operation
 * @param url_str URL string
 * @param ssl Enable SSL/TLS
 * @return Operation result
 */
sim_state_t sim_http_post_init(const char* url_str, bool ssl);

/**
 * @brief Enter data mode for HTTP POST.
 *
 * Call this and then send data to post over serial.
 *
 * @param size Data size in bytes
 * @param time Timeout in milliseconds
 * @return Operation result
 */
sim_state_t sim_http_post_enter_data(uint32_t size, uint32_t time);

/**
 * @brief Execute HTTP POST operation
 * @return Operation result
 */
sim_state_t sim_http_post(void);

/**
 * @brief Read HTTP response data
 * @param address Start address
 * @param buf_size Buffer size
 * @param buf Buffer to store response
 * @return Number of bytes read
 */
uint32_t sim_http_read_response(uint32_t address, uint32_t buf_size,
                                uint8_t* buf);

// TCP

/**
 * @brief Initialize TCP connection
 * @param url_str Server URL
 * @param port Server port
 * @param ssl Enable SSL/TLS
 * @return true if successful, false otherwise
 */
bool sim_tcp_init(const char* url_str, uint16_t port, bool ssl);

// SMS

/**
 * @brief Send SMS message
 * @param phone_number Recipient phone number
 * @param str Message text
 * @return true if successful, false otherwise
 */
bool sim_send_sms(const char* phone_number, const char* str);

/** @} */ /* End of sim_api group */
/** @} */ /* End of hub group */

#ifdef __cplusplus
}
#endif

#endif // SIM_H
