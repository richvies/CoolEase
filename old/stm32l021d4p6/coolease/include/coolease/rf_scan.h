#ifndef RF_SCAN_H
#define RF_SCAN_H

#include <stdbool.h>

#define RECEIVER 		true
#define TRANSMITTER		false

void rfs_init(bool r, uint8_t power);
void rfs_next(void);

#endif