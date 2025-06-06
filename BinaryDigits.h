/*
 * @File: BinaryDigits.c
 * @Author: Aldrin John O. Manalansan (ajom)
 * @Email: aldrinjohnolaermanalansan@gmail.com
 * @Brief: Helpers related to manipulating binary digits
 * @LastUpdate: June 7, 2025
 * 
 * Copyright (C) 2025  Aldrin John O. Manalansan  <aldrinjohnolaermanalansan@gmail.com>
 * 
 * This Source Code is served under Open-Source AJOM License
 * You should have received a copy of License_OS-AJOM
 * along with this source code. If not, see:
 * <https://raw.githubusercontent.com/Aldrin-John-Olaer-Manalansan/AJOM_License/refs/heads/main/LICENSE_AJOM-OS>
 */

#ifndef BINARYDIGITS_H
#define BINARYDIGITS_H

#define MACRO_COMPUTE_LOG2_2( n) ((n & 0x2       ) ? 1 : 0)
#define MACRO_COMPUTE_LOG2_4( n) ((n & 0xC       ) ? ( 2 + MACRO_COMPUTE_LOG2_2( n >>  2)) : (MACRO_COMPUTE_LOG2_2( n)))
#define MACRO_COMPUTE_LOG2_8( n) ((n & 0xF0      ) ? ( 4 + MACRO_COMPUTE_LOG2_4( n >>  4)) : (MACRO_COMPUTE_LOG2_4( n)))
#define MACRO_COMPUTE_LOG2_16(n) ((n & 0xFF00    ) ? ( 8 + MACRO_COMPUTE_LOG2_8( n >>  8)) : (MACRO_COMPUTE_LOG2_8( n)))
#define MACRO_COMPUTE_LOG2_32(n) ((n & 0xFFFF0000) ? (16 + MACRO_COMPUTE_LOG2_16(n >> 16)) : (MACRO_COMPUTE_LOG2_16(n)))
#define MACRO_COUNT_BITS_OCCUPIED(n) (MACRO_COMPUTE_LOG2_32(n)+1)

#define MACRO_POW2(exponent) (1U << exponent)
#define MACRO_2NDPOW(base) ((uint32_t)base * (uint32_t)base)
#define MACRO_4THPOW(base) (MACRO_2NDPOW(base) * MACRO_2NDPOW(base))
#define MACRO_8THPOW(base) (MACRO_4THPOW(base) * MACRO_4THPOW(base))
#define MACRO_POW(base, exponent) \
    ((exponent) == 0 ? 1 : \
    (exponent) == 1 ? ((uint32_t)base) : \
    (exponent) == 2 ? MACRO_2NDPOW(base) : \
    (exponent) == 3 ? MACRO_2NDPOW(base) * (uint32_t)base : \
    (exponent) == 4 ? MACRO_4THPOW(base) : \
    (exponent) == 5 ? MACRO_4THPOW(base) * (uint32_t)base : \
    (exponent) == 6 ? MACRO_4THPOW(base) * MACRO_2NDPOW(base) : \
    (exponent) == 7 ? MACRO_4THPOW(base) * MACRO_2NDPOW(base) * (uint32_t)base : \
    (exponent) == 8 ? MACRO_8THPOW(base) : \
    (exponent) == 9 ? MACRO_8THPOW(base) * (uint32_t)base : \
    (exponent) == 10 ? MACRO_8THPOW(base) * MACRO_2NDPOW(base) : 1 /* Default if not supported */)


#endif
