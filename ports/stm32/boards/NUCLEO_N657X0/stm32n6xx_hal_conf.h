/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2019 Damien P. George
 */
#ifndef MICROPY_INCLUDED_STM32N6XX_HAL_CONF_H
#define MICROPY_INCLUDED_STM32N6XX_HAL_CONF_H

// Oscillator values in Hz
#define HSE_VALUE (48000000)
#define LSE_VALUE (32768)
//#define EXTERNAL_I2S1_CLOCK_VALUE (48000)
//#if defined(STM32N6C1xx) || defined(STM32N6B1xx) || defined(STM32N6B0xx)
//#define EXTERNAL_I2S2_CLOCK_VALUE (48000)
//#endif

// Oscillator timeouts in ms
#define HSE_STARTUP_TIMEOUT (100)
#define LSE_STARTUP_TIMEOUT (5000)

#include "boards/stm32n6xx_hal_conf_base.h"

#endif // MICROPY_INCLUDED_STM32N6XX_HAL_CONF_H
