/*******************************************************************************
* Title                 :   HAL SPI Interface Implementations
* Filename              :   HAL_SPI_Interface
* Author                :   Austin Pedigo
* Origin Date           :   2024-02-06
* Version               :   1.1.1
* Compiler              :   ARM_EABI_NONE_GCC
* Target                :   STM32F103C8
* Notes                 :   None
********************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
*  2024-01-06   dev 1.1.1   Austin Pedigo  Initial Release.
*
********************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "HAL_ADC_Interface.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/


/******************************************************************************
* Module Typedefs
*******************************************************************************/


/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
ADC_Mem_Map_Ptr adc_1_mem_map = (ADC_Mem_Map_Ptr)0x40012400UL;
ADC_Mem_Map_Ptr adc_2_mem_map = (ADC_Mem_Map_Ptr)0x40012800UL;

/******************************************************************************
* Function Definitions
*******************************************************************************/
void ADC_HAL_Init(adc_config_t *config) {
    // Select ADC interface
    ADC_Mem_Map_Ptr adc_mem_map;

    if (config->interface == adc_interface_1) {
        adc_mem_map = adc_1_mem_map;
    } else {
        adc_mem_map = adc_2_mem_map;
    }

    // Configure ADC control registers
    adc_mem_map->ADC_CR1 &= ~(1UL << 0); // Clear all bits for configuration

    adc_mem_map->ADC_CR1 |= (config->resolution << 24)
    		| (config->clk_div << 16)
			| (config->external_trigger << 6)
			| (config->data_alignment << 5)
			| (config->mode << 0);

    adc_mem_map->ADC_CR2 &= ~(1UL << 8); // Clear DMA enable bit

    if (config->dma_status == dma_enable) {
        adc_mem_map->ADC_CR2 |= (1UL << 8); // Set DMA enable bit
    }

    // Configure ADC channel selection
    adc_mem_map->ADC_SQR3 &= ~(1UL << 0); // Clear all bits for channel selection
    adc_mem_map->ADC_SQR3 |= (config->channel << 0);

    // Start ADC
    adc_mem_map->ADC_CR2 |= (1UL << 0); // Set ADON bit to start ADC
}

/*************** END OF FUNCTIONS *********************************************/






