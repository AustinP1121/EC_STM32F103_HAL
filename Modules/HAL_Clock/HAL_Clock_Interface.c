/*******************************************************************************
* Title                 :   HAL Clock Interface Implementations
* Filename              :   HAL_Clock_Interface
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
#include "HAL_Clock_Interface.h"

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


/******************************************************************************
* Function Definitions
*******************************************************************************/

void RCC_Clock_HAL_SPI_Set(spi_interface_t interface_num, clock_status_t status)
{
	//need a way to tell which register to write to

	switch(interface_num)
	{
	case SPI_1:
		if(status == ENABLE)
		{
			Driver_Clock_Bit_Write(APB2ENR, SPI_1);
		}
		else
		{
			Driver_Clock_Bit_Clear(APB2ENR, SPI_1);
		}
		break;
	case SPI_2:
		if(status == ENABLE)
		{
			Driver_Clock_Bit_Write(APB1ENR, SPI_2);
		}
		else
		{
			Driver_Clock_Bit_Clear(APB1ENR, SPI_2);
		}
		break;
	case SPI_3:
		if(status == ENABLE)
		{
			Driver_Clock_Bit_Write(APB1ENR, SPI_3);
		}
		else
		{
			Driver_Clock_Bit_Clear(APB1ENR, SPI_3);
		}
		break;
	default:
		//TODO: invoke error handler
		break;
	}
}

void RCC_Clock_HAL_DMA_Set(dma_channel_t channel, clock_status_t status)
{

}

void RCC_Clock_HAL_I2C_Set(i2c_interface_t interface_num, clock_status_t status)
{

}

void RCC_Clock_HAL_ADC_Set(adc_select_t interface_num, clock_status_t status)
{

}

void RCC_Clock_HAL_UART_Set(uart_select_t interface_num, clock_status_t status)
{

}

void RCC_Clock_HAL_AFIOEN_Set()
{

}

void RCC_Clock_HAL_GPIO_Set(port_number_t port_num, clock_status_t status)
{

}

void RCC_Clock_HAL_Timer_Set(timer_select_t timer_num, clock_status_t status)
{

}

void RCC_Clock_HAL_Write_Reg(uint32_t *register_address, uint32_t write_value)
{

}

uint32_t RCC_Clock_HAL_Read_Reg(uint32_t *register_address)
{
	return 0;
}

/*************** END OF FUNCTIONS ***************************************************************************/






