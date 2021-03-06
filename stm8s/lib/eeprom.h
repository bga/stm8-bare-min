#ifndef EEPROM_H
#define EEPROM_H

#include "stm8s.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EEPROM_START_ADDR      0x4000
#define EEPROM_END_ADDR        0x407F

#if 0
  EEMEM Settings settings;
#endif

#ifdef __ICCSTM8__
  #define EEMEM __eeprom
#endif //# __ICCSTM8__

#ifdef __SDCC__
  #define EEMEM __at(EEPROM_START_ADDR)
#endif //# __SDCC__


/* Option bytes */
#define OPT0                   _MEM_(0x4800)
#define OPT1                   _MEM_(0x4801)
#define NOPT1                  _MEM_(0x4802)
#define OPT2                   _MEM_(0x4803)
#define NOPT2                  _MEM_(0x4804)
#define OPT3                   _MEM_(0x4805)
#define NOPT3                  _MEM_(0x4806)
#define OPT4                   _MEM_(0x4807)
#define NOPT4                  _MEM_(0x4808)
#define OPT5                   _MEM_(0x4809)
#define NOPT5                  _MEM_(0x480A)

/**
 * Enable write access to EEPROM.
 */
void eeprom_unlock();


/**
 * Enable write access to option bytes.
 * EEPROM must be unlocked first.
 */
void option_bytes_unlock();


/**
 * Disable write access to EEPROM.
 */
void eeprom_lock();

/**
 * Wait until programming is finished.
 * Not necessary on devices with no RWW support.
 */
void eeprom_wait_busy();

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* EEPROM_H */
