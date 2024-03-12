/*******************************************************************************
* Title                 :   HAL DMA Interface Implementations
* Filename              :   HAL_DMA_Interface
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
#include "HAL_DMA_Interface.h"

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
DMA_Channel_Config_Map_Ptr DMA_Channel_Config_Map =
		((DMA_Channel_Config_Map_Ptr) DMA1_BASE_ADDR);

DMA_Channel_X_Map_Ptr DMA_Channel_1_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_1_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_2_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_2_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_3_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_3_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_4_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_4_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_5_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_5_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_6_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_6_ADDR);
DMA_Channel_X_Map_Ptr DMA_Channel_7_Map =
		(DMA_Channel_X_Map_Ptr)(DMA1_CHANNEL_7_ADDR);

/******************************************************************************
* Function Definitions
*******************************************************************************/
void DMA_HAL_Config_Channel(dma_config_t * config)
{
	switch(config->channel)
	{
	case channel_1:
		DMA_Write_Channel(DMA_Channel_1_Map, config);
		break;
	case channel_2:
		DMA_Write_Channel(DMA_Channel_2_Map, config);
		break;
	case channel_3:
		DMA_Write_Channel(DMA_Channel_3_Map, config);
		break;
	case channel_4:
		DMA_Write_Channel(DMA_Channel_4_Map, config);
		break;
	case channel_5:
		DMA_Write_Channel(DMA_Channel_5_Map, config);
		break;
	case channel_6:
		DMA_Write_Channel(DMA_Channel_6_Map, config);
		break;
	case channel_7:
		DMA_Write_Channel(DMA_Channel_7_Map, config);
		break;
	default:
		break;
	}
}

void DMA_HAL_Disable_Channel(dma_channel_t channel_num)
{
	switch(channel_num)
	{
	case channel_1:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_2:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_3:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_4:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_5:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_6:
			//disable channel
			DMA_Channel_1_Map->CCRx &= ~(1UL << 0);
			break;
	case channel_7:
		default:
			break;
	}
}

void DMA_HAL_Write_Reg(uint32_t * reg_addr, const uint32_t value)
{
	*reg_addr = value;
}

uint32_t DMA_HAL_Read_Reg(const uint32_t * reg_addr)
{
	uint32_t reg_value = 0;

	reg_value = *reg_addr;

	return reg_value;
}

void DMA_Write_Channel(DMA_Channel_X_Map_Ptr dma_ptr_map, dma_config_t * config)
{
	//disable the dma channel
	dma_ptr_map->CCRx &= ~(1UL << 0);

	//set the peripheral address
	dma_ptr_map->CPARx = config->peripheral_addr;

	//set the second point's memory address
	dma_ptr_map->CMARx = config->second_source_addr;

	//configure the number of data to be transmitted
	dma_ptr_map->CNDTRx = config->data_count;

	//set the channel priority level
	dma_ptr_map->CCRx |= (config->channel_priority << 12);

	//set data direction, send or receive
	dma_ptr_map->CCRx |= (config->data_direction << 4);

	//set data acquisition mode
	if(config->data_acq_mode == circular_mode)
	{
		dma_ptr_map->CCRx |= (1UL << 5);
	}
	else if(config->data_acq_mode == mem_mem_mode)
	{
		dma_ptr_map->CCRx |= (1UL << 14);
	}

	//set the peripheral memory size
	dma_ptr_map->CCRx |= (config->periph_mem_size << 8);

	//set the second memory size
	dma_ptr_map->CCRx |= (config->memory_mem_size << 10);

	//enable the channel
	dma_ptr_map->CCRx |= (1UL << 0);
}


/*************** END OF FUNCTIONS ***************************************************************************/






