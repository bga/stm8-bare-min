#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


#define I2C_READ            0x01
#define I2C_WRITE           0x00

/**
 * Initialize I2C at 100kHz, 7-bit addressing mode.
 *
 * SDA -> PB5
 * SCL -> PB4
 */
void i2c_init();

/**
 * Generate START condition.
 */
void i2c_start();

/**
 * Generate STOP condition.
 */
void i2c_stop();

/**
 * Write one byte.
 *
 * @param data
 */
void i2c_write(uint_fast8_t data);

/**
 * Write slave address.
 *
 * @param addr slave address (must be shifted!)
 */
void i2c_write_addr(uint_fast8_t addr);

/**
 * Read >= 2 bytes. STOP is generated automatically.
 *
 * @param buf destination buffer
 * @param len buffer length
 */
void i2c_read_arr(uint8_t *buf, int len);

/*
 * Read one byte. STOP is generated automatically.
 */
uint_fast8_t i2c_read();

#ifdef __cplusplus
} // extern "C"
#endif


#endif /* I2C_H */

