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

// Machine is the HAL for low-level, hardware accelerated functions. It is not
// meant to simplify APIs, its only meant to unify them so that other modules
// do not require port specific logic.
//
// This file includes externs for all functions a port should implement to
// support the machine module.

#ifndef __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_I2C_H__
#define __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_I2C_H__

#include "py/obj.h"

#include "common-hal/microcontroller/types.h"
#include "common-hal/nativeio/types.h"

// Type object used in Python. Should be shared between ports.
extern const mp_obj_type_t nativeio_i2c_type;

// Initializes the hardware peripheral.
extern void common_hal_nativeio_i2c_construct(nativeio_i2c_obj_t *self,
                                              const mcu_pin_obj_t * scl,
                                              const mcu_pin_obj_t * sda,
                                              uint32_t frequency);

extern void common_hal_nativeio_i2c_deinit(nativeio_i2c_obj_t *self);

extern bool common_hal_nativeio_i2c_try_lock(nativeio_i2c_obj_t *self);
extern bool common_hal_nativeio_i2c_has_lock(nativeio_i2c_obj_t *self);
extern void common_hal_nativeio_i2c_unlock(nativeio_i2c_obj_t *self);

// Probe the bus to see if a device acknowledges the given address.
extern bool common_hal_nativeio_i2c_probe(nativeio_i2c_obj_t *self, uint8_t addr);

// Write to the device and return 0 on success or an appropriate error code from mperrno.h
extern uint8_t common_hal_nativeio_i2c_write(nativeio_i2c_obj_t *self, uint16_t address,
                                             const uint8_t * data, size_t len,
                                             bool stop);

// Reads memory of the i2c device picking up where it left off and return 0 on
// success or an appropriate error code from mperrno.h
extern uint8_t common_hal_nativeio_i2c_read(nativeio_i2c_obj_t *self, uint16_t address,
                                            uint8_t * data, size_t len);

#endif // __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_I2C_H__
