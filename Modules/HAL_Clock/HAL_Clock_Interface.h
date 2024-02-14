/*****************************************************************************
* Title                 :   HAL Clock Interface
* Filename              :   HAL_Clock_Interface.h
* Author                :   Austin Pedigo
* Origin Date           :   2024-01-25
* Version               :   dev1.1.1
* Compiler              :   ARM-NONE-EABI-GCC
* Target                :   STM32F103C8
* Notes                 :   None
*/

/*****************************************************************************
 * 							CHANGE LIST
 *
 * 		Date		Version		   Author		Description:
 * 	 2024-01-25	   dev 1.1.1	Austin Pedigo   Created and filled interface.
 *
 *****************************************************************************/
#ifndef HAL_CLOCK_INTERFACE_H_

#define HAL_CLOCK_INTERFACE_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "../../EC_PSD_STM32F103_HAL.c"
#include "Driver/Clock_Driver.h"

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/


/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/

typedef enum adc_select
{
	ADC_1 = 9,
	ADC_2 = 10
} adc_select_t;

typedef enum dma_channel
{
	DMA_1,
	DMA_2
} dma_channel_t;

typedef enum i2c_interface
{
	I2C_1 = 21,
	I2C_2 = 22
}i2c_interface_t;

typedef enum timer_select
{
	TIM_1 = 11,

	TIM_2 = 0,

	TIM_3 = 1,

	TIM_4 = 2,

	TIM_5 = 3,

	TIM_6 = 4,

	TIM_7 = 5,

	TIM_8 = 13,

	TIM_9 = 19,

	TIM_10 = 20,

	TIM_11 = 21,

	TIM_12 = 6,

	TIM_13 = 7,

	TIM_14 = 8
} timer_select_t;

typedef enum uart_select
{
	UART_1 = 14,

	UART_2 = 17,

	UART_3 = 18,

	UART_4 = 19,

	UART_5 = 20
} uart_select_t;

typedef enum clock_status
{
	DISABLE,

	ENABLE
} clock_status_t;

typedef enum spi_interface
{
	SPI_1 = 12,

	SPI_2 = 14,

	SPI_3 = 15
} spi_interface_t;

typedef enum port_number
{
	/**Port A clock enable bit 2, RCC_APB2ENR*/
	PORT_A = 2,

	/**Port B clock enable bit 3, RCC_APB2ENR*/
	PORT_B = 3,

	/**Port C clock enable bit 4, RCC_APB2ENR*/
	PORT_C = 4,

	/**Port D clock enable bit 5, RCC_APB2ENR*/
	PORT_D = 5,

	/**Port E clock enable bit 6, RCC_APB2ENR*/
	PORT_E = 6
} port_number_t;

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
/**
 * Disables the clock for the selected SPI interface.
 * @param interface_num: chooses one of the SPI interfaces
 * 	@see spi_interface_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_SPI(spi_interface_t interface_num, clock_status_t status);

/**
 * Sets the clock for the selected DMA channel.
 * @param interface_num: chooses one of the DMA channels,
 *	@see dma_channel_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_DMA_Set(dma_channel_t channel, clock_status_t status);

/**
 * Sets the clock for the selected I2C interface.
 * @param interface_num: chooses one of the I2C interfaces,
 *	@see i2c_channel_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_I2C_Set(i2c_interface_t interface_num, clock_status_t status);

/**
 * Sets the clock for the selected ADC interface.
 * @param interface_num: chooses one of the interfaces,
 *	@see adc_select_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_ADC_Set(adc_select_t interface_num, clock_status_t status);

/**
 * Sets the clock for the selected UART channel.
 * @param interface_num: chooses one of the UART channels,
 *	@see uart_select_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_UART_Set(uart_select_t interface_num, clock_status_t status);

/**
 * Sets the clock for the alternative function peripherals.
 */
void RCC_Clock_HAL_AFIOEN_Set();

/**
 * Sets the clock for the selected GPIO port.
 * @param port_num: chooses one of the UART channels,
 *	@see port_number_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_GPIO_Set(port_number_t port_num, clock_status_t status);

/**
 * Sets the clock for the selected timer.
 * @param timer_num: chooses one of the UART channels,
 *	@see timer_select_t
 * @param status: disable (0) or enable (1)
 */
void RCC_Clock_HAL_Timer_Set(timer_select_t timer_num, clock_status_t status);

/**
 * Writes to an RCC register.
 * @param register_address: physical address of the register.
 * @param write_value: value to write to the register.
 */
void RCC_Clock_HAL_Write_Reg(uint32_t* register_address, uint32_t const write_value);

/**
 * Retrieves and returns the value of a register.
 * @param register_address: physical address of the register.
 */
uint32_t RCC_Clock_HAL_Read_Reg(uint32_t* register_address);


#endif

/***END OF FILE***************************************************************/
