#ifndef SPI_H
#define SPI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialize SPI in MODE1.
 *
 * Pinout:
 * SCK  -> PC5
 * MOSI -> PC6
 * MISO -> PC7
 * CS   -> user defined
 */
void SPI_init();

void SPI_write(uint8_t data);

uint8_t SPI_read();

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* SPI_H */

