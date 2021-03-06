/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Scott Shawcroft
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __MICROPY_INCLUDED_SHARED_MODULE_BITBANGIO_TYPES_H__
#define __MICROPY_INCLUDED_SHARED_MODULE_BITBANGIO_TYPES_H__

#include "common-hal/nativeio/DigitalInOut.h"

#include "py/obj.h"

typedef struct {
    mp_obj_base_t base;
    nativeio_digitalinout_obj_t scl;
    nativeio_digitalinout_obj_t sda;
    uint32_t us_delay;
    volatile bool locked;
} bitbangio_i2c_obj_t;

typedef struct {
    mp_obj_base_t base;
    nativeio_digitalinout_obj_t pin;
} bitbangio_onewire_obj_t;

typedef struct {
    mp_obj_base_t base;
    nativeio_digitalinout_obj_t clock;
    nativeio_digitalinout_obj_t mosi;
    nativeio_digitalinout_obj_t miso;
    uint32_t delay_half;
    bool has_miso:1;
    bool has_mosi:1;
    uint8_t polarity:1;
    uint8_t phase:1;
    volatile bool locked:1;
} bitbangio_spi_obj_t;

#endif // __MICROPY_INCLUDED_SHARED_MODULE_BITBANGIO_TYPES_H__
