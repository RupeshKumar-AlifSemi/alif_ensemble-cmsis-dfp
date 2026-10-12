/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */
/****************************************************************************
 * @file     Driver_ADC.h
 * @author   Prabhakar Kumar
 * Email:    prabhakar.kumar@alifsemi.com
 * @version  V1.0.0
 * @date     22-feb-2022
 * @brief    ADC (Analog to digital conversion) Driver Definition.
 *******************************************************************************/
#ifndef DRIVER_ADC_H_
#define DRIVER_ADC_H_

#include "Driver_Common.h"

#ifdef _cplusplus
extern "C" {
#endif

#define ARM_ADC_API_VERSION              ARM_DRIVER_VERSION_MAJOR_MINOR(2, 0) /*API VERSION*/

#define _ARM_Driver_ADC12(n)             Driver_ADC12##n
#define ARM_Driver_ADC12(n)              _ARM_Driver_ADC12(n)

/**********ADC CONTROL CODE************/
#define ARM_ADC_SHIFT_CTRL               (0x01UL) /* ARM ADC SHIFT CONTROL                  */
#define ARM_ADC_SEQUENCER_CTRL           (0x02UL) /* ARM ADC SEQUENCER CONTROL              */
#define ARM_ADC_SEQUENCER_MSK_CH_CTRL    (0x03UL) /* ARM ADC SEQUENCER MASK CHANNEL CONTROL */
#define ARM_ADC_CHANNEL_INIT_VAL         (0x04UL) /* ARM ADC CHANNEL INITIAL CONTROL        */
#define ARM_ADC_COMPARATOR_A             (0x05UL) /* ARM ADC COMPARATOR A CONTROL           */
#define ARM_ADC_COMPARATOR_B             (0x06UL) /* ARM ADC COMPARATOR B CONTROL           */
#define ARM_ADC_THRESHOLD_COMPARISON     (0X07UL) /* ARM ADC THRESHOLD COMPARISON CONTROL   */
#define ARM_ADC_CONVERSION_MODE_CTRL     (0x08UL) /* ARM ADC CONVERSION MODE CONTROL        */
#define ARM_ADC_EXTERNAL_TRIGGER_ENABLE  (0x09UL) /* ARM ADC EXTERNAL TRIGGER ENABLE        */
#define ARM_ADC_EXTERNAL_TRIGGER_DISABLE (0x0AUL) /* ARM ADC EXTERNAL TRIGGER DISABLE       */
#define ARM_ADC_HARDWARE_AVERAGING_CTRL  (0x0BUL) /* ARM ADC SET HARDWARE AVERAGING         */
#define ARM_ADC_SAMPLE_WIDTH_CTRL        (0x0CUL) /* ARM ADC SAMPLE WIDTH CONTROL           */
#define ARM_ADC_DIFFERENTIAL_MODE_CTRL   (0x0DUL) /* ARM ADC DIFFERENTIAL MODE CONTROL      */
#define ARM_ADC_INPUT_CLOCK_DIV_CTRL     (0x0FUL) /* ARM ADC INPUT CLOCK DIVISOR CONTROL    */
#define ARM_ADC_SET_PGA_GAIN_CTRL        (0x10UL) /* ARM ADC SET PGA GAIN CONTROL           */
#define ARM_ADC_24_BIAS_CTRL             (0x11UL) /* ARM ADC 24 BIAS CONTROL                */
#define ARM_ADC_24_OUTPUT_RATE_CTRL      (0x12UL) /* ARM ADC 24 OUTPUT RATE CONTROL         */

/*********THRESHOLD COMPARSION**********/
#define ARM_ADC_ABOVE_A_AND_ABOVE_B      (0x00UL) /* ARM ADC THRESHOLD ABOVE A AND ABOVE B         */
#define ARM_ADC_BELOW_A_AND_BELOW_B      (0x01UL) /* ARM ADC THRESHOLD BELOW A AND BELOW B         */
#define ARM_ADC_BETWEEN_A_B_AND_OUTSIDE_A_B                                                        \
    (0x02UL) /* ARM ADC THRESHOLD BETWEEN A_B AND OUTSIDE A_B */

/**********ADC EVENT********************/
#define ARM_ADC_EVENT_CONVERSION_COMPLETE    (1 << 0) /* ARM ADC EVENT CONVERSION COMPLETE        */
#define ARM_ADC_COMPARATOR_THRESHOLD_ABOVE_A (1 << 1) /* ARM ADC COMPARATOR THRESHOLD ABOVE A */
#define ARM_ADC_COMPARATOR_THRESHOLD_ABOVE_B (1 << 2) /* ARM ADC COMPARATOR THRESHOLD ABOVE B */
#define ARM_ADC_COMPARATOR_THRESHOLD_BELOW_A (1 << 3) /* ARM ADC COMPARATOR THRESHOLD BELOW A */
#define ARM_ADC_COMPARATOR_THRESHOLD_BELOW_B (1 << 4) /* ARM ADC COMPARATOR THRESHOLD BELOW B */
#define ARM_ADC_COMPARATOR_THRESHOLD_BETWEEN_A_B                                                   \
    (1 << 5) /* ARM ADC COMPARATOR THRESHOLD BETWEEN A_B */
#define ARM_ADC_COMPARATOR_THRESHOLD_OUTSIDE_A_B                                                   \
    (1 << 6)                                    /* ARM ADC COMPARATOR THRESHOLD OUTSIDE A_B */
#define ARM_ADC_EVENT_CONTINUOUS_CONV_BUF_A   (1 << 7)  /* StartN: buf_a filled            */
#define ARM_ADC_EVENT_CONTINUOUS_CONV_BUF_B   (1 << 8)  /* StartN: buf_b filled            */
#define ARM_ADC_EVENT_CONTINUOUS_CONV_STOPPED (1 << 9)  /* StartN: Stop() partial-buf done */

/**********ADC CONVERSION OPERATION**********/
#define ARM_ADC_CONTINOUS_CH_CONV      (0x00) /* ARM ADC CHANNEL CONTINUOUS CONVERSION    */
#define ARM_ADC_SINGLE_SHOT_CH_CONV    (0x01) /* ARM ADC CHANNEL SINGLE CONVERSION        */

/**********ADC SCAN OPERATION**********/
#define ARM_ADC_MULTIPLE_CH_SCAN       (0x00) /* ARM ADC MULTIPLE CHANNEL SCAN MODE */
#define ARM_ADC_SINGLE_CH_SCAN         (0x01) /* ARM ADC SINGLE CHANNEL SCAN MODE   */

/**********ADC CHANNELS******/
#define ARM_ADC_CHANNEL_0              (0x00) /* ARM ADC CHANNEL 0 */
#define ARM_ADC_CHANNEL_1              (0x01) /* ARM ADC CHANNEL 1 */
#define ARM_ADC_CHANNEL_2              (0x02) /* ARM ADC CHANNEL 2 */
#define ARM_ADC_CHANNEL_3              (0x03) /* ARM ADC CHANNEL 3 */
#define ARM_ADC_CHANNEL_4              (0x04) /* ARM ADC CHANNEL 4 */
#define ARM_ADC_CHANNEL_5              (0x05) /* ARM ADC CHANNEL 5 */
#define ARM_ADC_CHANNEL_6              (0x06) /* ARM ADC CHANNEL 6 */
#define ARM_ADC_CHANNEL_7              (0x07) /* ARM ADC CHANNEL 7 */
#define ARM_ADC_CHANNEL_8              (0x08) /* ARM ADC CHANNEL 8 */

/****ADC MASK CHANNEL****/
#define ARM_ADC_MASK_CHANNEL_0         (1 << ARM_ADC_CHANNEL_0) /* ARM ADC MASK CHANNEL 0 */
#define ARM_ADC_MASK_CHANNEL_1         (1 << ARM_ADC_CHANNEL_1) /* ARM ADC MASK CHANNEL 1 */
#define ARM_ADC_MASK_CHANNEL_2         (1 << ARM_ADC_CHANNEL_2) /* ARM ADC MASK CHANNEL 2 */
#define ARM_ADC_MASK_CHANNEL_3         (1 << ARM_ADC_CHANNEL_3) /* ARM ADC MASK CHANNEL 3 */
#define ARM_ADC_MASK_CHANNEL_4         (1 << ARM_ADC_CHANNEL_4) /* ARM ADC MASK CHANNEL 4 */
#define ARM_ADC_MASK_CHANNEL_5         (1 << ARM_ADC_CHANNEL_5) /* ARM ADC MASK CHANNEL 5 */
#define ARM_ADC_MASK_CHANNEL_6         (1 << ARM_ADC_CHANNEL_6) /* ARM ADC MASK CHANNEL 6 */
#define ARM_ADC_MASK_CHANNEL_7         (1 << ARM_ADC_CHANNEL_7) /* ARM ADC MASK CHANNEL 7 */
#define ARM_ADC_MASK_CHANNEL_8         (1 << ARM_ADC_CHANNEL_8) /* ARM ADC MASK CHANNEL 8 */

/* External trigger macros */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_0 (1UL << 0) /* ARM ADC EXTERNAL TRIGGER SOURCE 0 */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_1 (1UL << 1) /* ARM ADC EXTERNAL TRIGGER SOURCE 1 */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_2 (1UL << 2) /* ARM ADC EXTERNAL TRIGGER SOURCE 2 */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_3 (1UL << 3) /* ARM ADC EXTERNAL TRIGGER SOURCE 3 */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_4 (1UL << 4) /* ARM ADC EXTERNAL TRIGGER SOURCE 4 */
#define ARM_ADC_EXTERNAL_TRIGGER_SRC_5 (1UL << 5) /* ARM ADC EXTERNAL TRIGGER SOURCE 5 */

/**
  \fn          ARM_DRIVER_VERSION ARM_ADC_GetVersion (void)
  \brief       Get the ADC driver version.
  \return      \ref ARM_DRIVER_VERSION

  \fn          ARM_ADC_CAPABILITIES ARM_ADC_GetCapabilities (void)
  \brief       Get the ADC driver capabilities.
  \return      \ref ARM_ADC_CAPABILITIES

  \fn          int32_t ARM_ADC_Initialize (ARM_ADC_SignalEvent_t cb_event)
  \brief       Initialize the ADC interface.
  \param[in]   cb_event  Pointer to the ADC event callback \ref ARM_ADC_SignalEvent
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_Uninitialize (void)
  \brief       De-initialize the ADC interface.
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_Start (void)
  \brief       Start ADC conversions.
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_Stop (void)
  \brief       Stop the ADC interface.
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_PowerControl (ARM_POWER_STATE state)
  \brief       Control ADC interface power.
  \param[in]   state  Power state
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_Control (uint32_t control, uint32_t arg)
  \brief       Control the ADC interface.
  \param[in]   control  Operation code
  \param[in]   arg      Optional argument for the operation
  \return      \ref execution_status

  \fn          int32_t ARM_ADC_StartN (void *buf_a, void *buf_b, uint32_t samples_per_buf)
  \brief       Arm ping-pong buffers for a continuous channel scan.
               The driver fills buf_a, signals ARM_ADC_EVENT_CONTINUOUS_CONV_BUF_A
               with the sample count in the callback value, then fills buf_b and
               signals ARM_ADC_EVENT_CONTINUOUS_CONV_BUF_B. If buf_b is NULL the
               capture is one-shot. Not supported in single-shot conversion mode.
               Stop during a running capture signals ARM_ADC_EVENT_CONTINUOUS_CONV_STOPPED
               with the number of samples written into the partial buffer.
  \param[in]   buf_a            Pointer to a uint32_t sample buffer. Required.
  \param[in]   buf_b            Second buffer, or NULL for one-shot capture.
  \param[in]   samples_per_buf  Capacity of each buffer. Must be a whole multiple
                                of the number of unmasked channels.
  \return      \ref execution_status

  \fn          uint32_t ARM_ADC_GetSampleCount (void)
  \brief       Return the number of samples written into the StartN buffer
               that is currently being filled.
  \return      samples written
*/

typedef void (*ARM_ADC_SignalEvent_t)(uint32_t event, uint8_t channel,
                                      uint32_t value); /**< Pointer to \ref ARM_ADC_SignalEvent */

typedef struct _ARM_ADC_CAPABILITIES {
    uint32_t Resolution: 1;  /* Resolution 12 or 20 bits*/
    uint32_t Reserved  : 31; /* Reserved                */
} ARM_ADC_CAPABILITIES;

/** @brief Access structure of the ADC driver. */
typedef struct ARM_DRIVER_ADC {
    ARM_DRIVER_VERSION (*GetVersion)(void);  /**< Pointer to \ref ARM_ADC_GetVersion */
    ARM_ADC_CAPABILITIES (*GetCapabilities)(void);  /**< Pointer to \ref ARM_ADC_GetCapabilities */
    int32_t (*Initialize)(ARM_ADC_SignalEvent_t cb_event);  /**< Pointer to \ref ARM_ADC_Initialize */
    int32_t (*Uninitialize)(void);  /**< Pointer to \ref ARM_ADC_Uninitialize */
    int32_t (*Start)(void);  /**< Pointer to \ref ARM_ADC_Start */
    int32_t (*Stop)(void);  /**< Pointer to \ref ARM_ADC_Stop */
    int32_t (*PowerControl)(ARM_POWER_STATE state);  /**< Pointer to \ref ARM_ADC_PowerControl */
    int32_t (*Control)(uint32_t Control, uint32_t arg);  /**< Pointer to \ref ARM_ADC_Control */
    int32_t (*StartN)(void *buf_a, void *buf_b, uint32_t samples_per_buf);  /**< Pointer to \ref ARM_ADC_StartN */
    uint32_t (*GetSampleCount)(void);  /**< Pointer to \ref ARM_ADC_GetSampleCount */
} const ARM_DRIVER_ADC;

#ifdef _cplusplus
}
#endif
#endif /* DRIVER_ADC_H_ */

/************************ (C) COPYRIGHT ALIF SEMICONDUCTOR *****END OF FILE****/
