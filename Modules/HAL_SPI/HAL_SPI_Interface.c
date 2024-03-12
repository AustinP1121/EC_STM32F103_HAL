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
#include "HAL_SPI_Interface.h"

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
SPI_Interface_Map_Ptr SPI_1_Map_Ptr = ((SPI_Interface_Map_Ptr)(0x40013000UL));
SPI_Interface_Map_Ptr SPI_2_Map_Ptr = ((SPI_Interface_Map_Ptr)(0x40003800UL));
SPI_Interface_Map_Ptr SPI_3_Map_Ptr = ((SPI_Interface_Map_Ptr)(0x40003C00UL));

SPI_Interface_Map_Ptr current_interface = SPI_1_Map_Ptr;

/******************************************************************************
* Function Definitions
*******************************************************************************/
void SPI_HAL_Config_Interface_DMA(spi_config* config)
{
	switch((int)config->interface_num)
	{
	case spi_interface_1:
		//enable the DMA Rx
		SPI_1_Map_Ptr->CR2 |= (1UL << 0);

		//enable the DMA Tx
		SPI_1_Map_Ptr->CR2 |= (1UL << 1);

		SPI_Write_Config(SPI_1_Map_Ptr, config);
		break;
	case spi_interface_2:
		//enable the DMA Rx
		SPI_2_Map_Ptr->CR2 |= (1UL << 0);

		//enable the DMA Tx
		SPI_2_Map_Ptr->CR2 |= (1UL << 1);

		SPI_Write_Config(SPI_2_Map_Ptr, config);
		break;
	case spi_interface_3:
		//enable the DMA Rx
		SPI_1_Map_Ptr->CR2 |= (1UL << 0);

		//enable the DMA Tx
		SPI_1_Map_Ptr->CR2 |= (1UL << 1);

		//write the configuration to CR1
		SPI_Write_Config(SPI_3_Map_Ptr, config);
		break;
	default:
		break;
	}
}

void SPI_HAL_Config_Interface_Std(spi_config* config)
{
	switch((int)config->interface_num)
	{
	case spi_interface_1:
		//write the configuration to CR1
		SPI_Write_Config(SPI_1_Map_Ptr, config);
		break;
	case spi_interface_2:
		//write the configuration to CR1
		SPI_Write_Config(SPI_2_Map_Ptr, config);
		break;
	case spi_interface_3:
		//write the configuration to CR1
		SPI_Write_Config(SPI_3_Map_Ptr, config);
		break;
	default:
		break;
	}
}

void SPI_Write_Config(SPI_Interface_Map_Ptr interface_map_ptr, spi_config* config)
{
	//write the baud rate to BR[2:0], SPI_CR1
	interface_map_ptr->CR1 |= (config->baud_rate << 3);

	//write the clock phase (CPHA) and clock polarity (CPOL), SPI_CR1
	interface_map_ptr->CR1 |= (config->sck_mode);

	//write the data frame length (DFF), SPI_CR1
	interface_map_ptr->CR1 |= (config->data_frame_sz << 11);

	//write the frame format (LSBFIRST), SPI_CR1
	interface_map_ptr->CR1 |= (config->frame_format << 7);

	//write the software slave management mode (SSM), SPI_CR1
	interface_map_ptr->CR1 |= (config->ssm_status << 9);

	//write the configuration (MSTR), SPI_CR1
	interface_map_ptr->CR1 |= (config->config_stat << 2);

	//enable the spi interface
	interface_map_ptr->CR1 |= (config->spi_stat << 6);
}

uint16_t SPI_HAL_Interface_Slave_Read()
{

	uint16_t data_frame;



	return 0;
}

void SPI_HAL_Interface_Slave_Write(uint16_t data_frame)
{

}

uint16_t SPI_HAL_Interface_Rx_Buffer_Stat(spi_interface_t interface_num)
{
	uint16_t status = 0;

	uint16_t RXE_Avail = (1UL << 0);
	switch(interface_num)
	{
	case spi_interface_1:
		current_interface = SPI_1_Map_Ptr;

		if(current_interface->SR & RXE_Avail)
		{
			status = 1;
		}
		break;
	case spi_interface_2:
		current_interface = SPI_2_Map_Ptr;

		if(current_interface->SR & RXE_Avail)
		{
			status = 1;
		}
		break;
	case spi_interface_3:
		current_interface = SPI_3_Map_Ptr;

		if(current_interface->SR & RXE_Avail)
		{
			status = 1;
		}
		break;
	default:
		break;
	}

	return status;
}

void SPI_HAL_Write_Reg(uint16_t *reg_addr, uint16_t val)
{
	*reg_addr = val;
}

uint16_t SPI_HAL_Read_Reg(uint16_t *reg_addr)
{

	uint16_t var = 3;
	return var;
}

/*************** END OF FUNCTIONS ***************************************************************************/






