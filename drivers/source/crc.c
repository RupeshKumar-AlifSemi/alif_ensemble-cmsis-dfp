/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */

#include "crc.h"

/**
 @brief        Reflect the CRC 32 bit output
 */
uint32_t crc_bit_reflect(uint32_t input)
{
    uint32_t res = 0;
    uint32_t i, bit;

    for (i = 0; i < 32; i++) {
        bit  = (input >> i) & 1;
        bit  = bit << (32 - (i + 1));
        res |= bit;
    }

    return res;
}

/**
@brief      To calculate the CRC result for unaligned data
             1. It will take the aligned data for CRC result from the hardware.
             2. It will the Unaligned input data and its length.
             3. If the algorithm is 32 bit CRC then it will take the standard
                32 bit CRC Polynomial
             4. If the algorithm is 32 bit Custom CRC polynomial , it will take
                the polynomial entered from the user.
algorithm
*/
uint32_t crc_calculate_unaligned(uint32_t key, const uint8_t *input, uint32_t length, uint32_t poly)
{
    uint32_t crc, check_bit, polynomial;
    uint8_t  data;
    uint32_t i, j;

    crc        = key;

    /* Store the reflected polynomial */
    polynomial = crc_bit_reflect(poly);

    for (i = 0; i < length; i++) {
        data = input[i];
        for (j = 0; j < 8; j++) {
            check_bit   = (crc ^ data) & 1;
            crc       >>= 1;

            if (check_bit) {
                crc = crc ^ polynomial;
            }
            data >>= 1;
        }
    }
    return ~crc;
}

/**
                                  uint32_t len, uint32_t *data_out)
 @brief        Calculate the CRC output  for 8 bit CRC algorithm
 */
void crc_calculate_8bit(CRC_Type *crc, const void *data_in, uint32_t len, uint32_t *data_out)
{
    for (uint32_t count = 0; count < len; count++) {
        /* User input 8 bit data is storing into the DATA_IN_8 bit register */
        crc->CRC_DATA_IN_8_[0] = ((const uint8_t *) data_in)[count];
    }

    /* data_out pointer to store the CRC output */
    *data_out = (crc->CRC_OUT);
}

/**
                                   uint32_t len, uint32_t *data_out)
 @brief        Calculate the CRC output  for 16 bit CRC algorithm
 */
void crc_calculate_16bit(CRC_Type *crc, const void *data_in, uint32_t len, uint32_t *data_out)
{
    for (uint32_t count = 0; count < len; count++) {
        /* User input 8 bit data is storing into the DATA_IN_8 bit register */
        crc->CRC_DATA_IN_8_[0] = ((const uint8_t *) data_in)[count];
    }

    /* data_out pointer to store the CRC output */
    *data_out = (crc->CRC_OUT);
}

/**
                                   uint32_t len, uint32_t *data_out)
 @brief        Calculate the CRC output  for 32 bit CRC algorithm
 */
void crc_calculate_32bit(CRC_Type *crc, const void *data_in, uint32_t len, uint32_t *data_out)
{
    const uint32_t *data32;
    uint32_t        value;
    uint32_t        aligned_length = len;

    data32                         = (const uint32_t *) data_in;

    for (uint32_t count = 0; count < aligned_length / 4; count++) {
        value                   = *(data32++);

        /* User input 32 bit data is storing into the DATA_IN_32 bit register */
        crc->CRC_DATA_IN_32_[0] = value;
    }

    /* Store the CRC aligned output */
    *data_out = (crc->CRC_OUT);
}

/**
                                                  crc_transfer_t *transfer)
 @brief        Calculate the 32bit CRC output for the unaligned part
 */
void crc_calculate_32bit_unaligned_sw(CRC_Type *crc, crc_transfer_t *transfer)
{
    uint32_t       polynomial_status, control_val;
    uint32_t       custom;
    const uint8_t *input = (const uint8_t *) transfer->data_in + transfer->aligned_len;

    if (transfer->unaligned_len > 0) {
        polynomial_status = crc_custom_poly_enabled(crc);

        control_val       = crc_get_control_val(crc);

        /* Check for the custom polynomial bit  */
        if (polynomial_status) {
            /* assign the user polynomial */
            custom = crc_get_custom_poly(crc);
        } else {
            /* Assign the 32 bit CRC standard polynomial */
            custom = CRC_STANDARD_POLY;
        }

        if (control_val & CRC_INVERT) {
            /* Invert crc output */
            *transfer->data_out = ~(*transfer->data_out);
        }

        if (!(control_val & CRC_REFLECT)) {
            /* Reflect crc output */
            *transfer->data_out = crc_bit_reflect(*transfer->data_out);
        }

        /* Calculate the CRC for unaligned data */
        *transfer->data_out =
            crc_calculate_unaligned(*transfer->data_out, input, transfer->unaligned_len, custom);

        if (!(control_val & CRC_REFLECT)) {
            /* Reflect crc output */
            *transfer->data_out = crc_bit_reflect(*transfer->data_out);
        }

        if (!(control_val & CRC_INVERT)) {
            /* Invert crc output */
            *transfer->data_out = ~(*transfer->data_out);
        }
    }
}
