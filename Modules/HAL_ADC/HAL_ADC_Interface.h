/*****************************************************************************
* Title                 :   HAL ADC Interface
* Filename              :   HAL_ADC_Interface.h
* Author                :   Austin Pedigo
* Origin Date           :   2024-01-25
* Version               :   dev1.1.1
* Compiler              :   ARM-NONE-EABI-GCC
* Target                :   STM32F103C8
* Notes                 :   None
*/

#ifndef HAL_ADC_INTERFACE_H_

#define HAL_ADC_INTERFACE_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "../../EC_PSD_STM32F103_HAL.c"

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/

/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/
typedef struct
{
	uint32_t ADC_SR;
	uint32_t ADC_CR1;
	uint32_t ADC_CR2;
	uint32_t ADC_SMPR1;
	uint32_t ADC_SMPR2;
	uint32_t ADC_JOFRx[4];
	uint32_t ADC_HTR;
	uint32_t ADC_LTR;
	uint32_t ADC_SQR1;
	uint32_t ADC_SQR2;
	uint32_t ADC_SQR3;
	uint32_t ADC_JSQR;
	uint32_t ADC_JDRx[4];
	uint32_t ADC_DR;
} volatile * const ADC_Mem_Map_Ptr;

typedef enum {
    adc_resolution_12bit = 0b00,
    adc_resolution_10bit = 0b01,
    adc_resolution_8bit = 0b10,
    adc_resolution_6bit = 0b11
} adc_resolution_t;

typedef enum {
    adc_clk_div_2 = 0b000,
    adc_clk_div_4 = 0b001,
    adc_clk_div_6 = 0b010,
    adc_clk_div_8 = 0b011
} adc_clk_div_t;

typedef enum {
    adc_external_trigger_tim1_cc1 = 0b0000,
    adc_external_trigger_tim1_cc2 = 0b0001,
    adc_external_trigger_tim1_cc3 = 0b0010,
    adc_external_trigger_tim2_cc2 = 0b0011,
} adc_external_trigger_t;

typedef enum {
    adc_data_alignment_right = 0b0,
    adc_data_alignment_left = 0b1
} adc_data_alignment_t;

typedef enum {
    adc_mode_single = 0b00,
    adc_mode_continuous = 0b01,
} adc_mode_t;

typedef enum {
    adc_channel_0 = 0b0000,
    adc_channel_1 = 0b0001,
    adc_channel_2 = 0b0010,
    adc_channel_3 = 0b0011,
} adc_channel_t;

typedef enum {
	dma_enable,
	dma_disable
} adc_dma_status_t;

typedef enum
{
	adc_interface_1,
	adc_interface_2
} adc_interface_t;

typedef struct {
    adc_resolution_t resolution;
    adc_clk_div_t clk_div;
    adc_external_trigger_t external_trigger;
    adc_data_alignment_t data_alignment;
    adc_mode_t mode;
    adc_channel_t channel;
    adc_interface_t interface;
    adc_dma_status_t dma_status;
} adc_config_t;

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
// ADC Initialization
void ADC_HAL_Init(adc_config_t *config);

#endif

/***END OF FILE***************************************************************/
