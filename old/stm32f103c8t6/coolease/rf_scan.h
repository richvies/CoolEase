#ifndef RF_SCAN_H
#define RF_SCAN_H

#define RECEIVER 		true
#define TRANSMITTER		false

void rfs_init(bool r, uint8_t power);
void rfs_next(void);

#endif