/*
 *  libsuola - An engine gluing together OpenSSL and NaCl-derived crypto.
 *  Copyright (C) 2018 TTY Foundation sr
 *
 *  This file is part of libsuola.
 *
 *  libsuola is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU Lesser General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or (at your
 *  option) any later version.
 *
 *  libsuola is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "providers/api/base.h"

#include "debug/debug.h"
#include <sodium.h>

int suola_implementation_init(void)
{
    if (sodium_init() == -1) {
        errorf("sodium_init failed\n");
        return -1;
    }

    return 0;
}

#include "providers/api/rng.h"

int suola_randombytes_buf(void * const buf, const size_t len)
{
    randombytes_buf(buf, len);
    return 0;
}

/* vim: set ts=4 sw=4 tw=78 et : */
