/*****************************************************************************
* Title                 :   HAL Clock Interface
* Filename              :   HAL_Clock_Interface.h
* Author                :   Austin Pedigo
* Origin Date           :   2024-01-25
* Version               :   dev1.1.1
* Compiler              :   ARM-NONE-EABI-GCC
* Target                :   STM32F103xx
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


/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/


/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/

/**
 * Enum containing bit locations for each peripheral within the clock
 * enable registers.
 *
 * Each peripheral clock is enabled or disabled using the following registers:
 * 	- RCC_APBENR
 * 	- RCC_APB1ENR
 * 	- RCC_APB2ENR
 *
 * Ex. the clock enable bit for Port A is located at
 * location 2 within the RCC_APB2ENR register.
 */

enum peripheral_id_type{

	/**DMA 1 clock enable bit 0, RCC_APBENR*/
	DMA_1 = 0,

	/**DMA 2 clock enable bit 1, RCC_APBENR*/
	DMA_2 = 1,

	/**SRAM Interface clock enable bit 2, RCC_APBENR*/
	SRAM_INTERFACE = 2,

	/**FLITF clock enable bit 4, RCC_APBENR*/
	FLITF = 4,

	/**CRC clock enable bit 6, RCC_APBENR*/
	CRC = 6,

	/**USB OTG FS clock enable bit 12, RCC_APBENR*/
	USB_OTG_FS = 12,

	/**Ethernet MAC clock enable bit 14, RCC_APBENR*/
	ETHERNET_MAC = 14,

	/**Ethernet MAC TX clock enable bit 15, RCC_APBENR*/
	ETHERNET_MAX_TX = 15,

	/**Ethernet MAC RX clock enable bit 16, RCC_APBENR*/
	ETHERNET_MAC_RX = 16,


	/**Timer 2 clock enable bit 0, RCC_APB1ENR*/
	TIM_2 = 0,

	/**Timer 3 clock enable bit 1, RCC_APB1ENR*/
	TIM_3 = 1,

	/**Timer 4 clock enable bit 2, RCC_APB1ENR*/
	TIM_4 = 2,

	/**Timer 5 clock enable bit 3, RCC_APB1ENR*/
	TIM_5 = 3,

	/**Timer 6 clock enable bit 4, RCC_APB1ENR*/
	TIM_6 = 4,

	/**Timer 3 clock enable bit 5, RCC_APB1ENR*/
	TIM_7 = 5,

	/**Window Watchdog clock enable bit 11, RCC_APB1ENR*/
	WIN_WATDOG = 11,

	/**SPI 2 clock enable bit 14, RCC_APB1ENR*/
	SPI_2 = 14,

	/**SPI 3 clock enable bit 15, RCC_APB1ENR*/
	SPI_3 = 15,

	/**USART 2 clock enable bit 17, RCC_APB1ENR*/
	USART_2 = 17,

	/**USART 3 clock enable bit 18, RCC_APB1ENR*/
	USART_3 = 18,

	/**USART 4 clock enable bit 19, RCC_APB1ENR*/
	USART_4 = 19,

	/**USART 5 clock enable bit 20, RCC_APB1ENR*/
	USART_5 = 20,

	/**I2C 1 clock enable bit 21, RCC_APB1ENR*/
	I2C_1 = 21,

	/**I2C 2 clock enable bit 22, RCC_APB1ENR*/
	I2C_2 = 22,

	/**CAN 1 clock enable bit 25, RCC_APB1ENR*/
	CAN_1 = 25,

	/**CAN 2 clock enable bit 26, RCC_APB1ENR*/
	CAN_2 = 26,

	/**Backup Interface clock enable bit 27, RCC_APB1ENR*/
	BACKUP_INTERFACE = 27,

	/**Power Interface clock enable bit 28, RCC_APB1ENR*/
	POWER_INTERFACE = 28,

	/**DAC clock enable bit 29, RCC_APB1ENR*/
	DAC = 29,


	/**Alternate Function clock enable bit 1, RCC_APB2ENR*/
	ALT_FUNC = 1,

	/**Port A clock enable bit 2, RCC_APB2ENR*/
	PORT_A = 2,

	/**Port B clock enable bit 3, RCC_APB2ENR*/
	PORT_B = 3,

	/**Port C clock enable bit 4, RCC_APB2ENR*/
	PORT_C = 4,

	/**Port D clock enable bit 5, RCC_APB2ENR*/
	PORT_D = 5,

	/**Port E clock enable bit 6, RCC_APB2ENR*/
	PORT_E = 6,

	/**ADC 1 clock enable bit 9, RCC_APB2ENR*/
	ADC_1 = 9,

	/**ADC 2 clock enable bit 10, RCC_APB2ENR*/
	ADC_2 = 10,

	/**Timer 1 clock enable bit 11, RCC_APB2ENR*/
	TIM_1 = 11,

	/**SPI 1 clock enable bit 12, RCC_APB2ENR*/
	SPI_1 = 12,

	/**USART 1 clock enable bit 14, RCC_APB2ENR*/
	USART_1 = 14
};

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/

/**
 * Enables the clock for a given peripheral.
 * @param peripheral_id: peripheral type that correlates to a bit location within
 * the RCC registers.
 */
void RCC_Clock_HAL_Enable(int peripheral_id);

/**
 * Disables the clock for a given peripheral.
 * @param peripheral_id: peripheral type that correlates to a bit location within
 * the RCC registers.
 */
void RCC_Clock_HAL_Disable(int peripheral_id);

/**
 * Resets the clock for a given peripheral.
 * @param peripheral_id: peripheral type that correlates to a bit location within
 * the RCC registers.
 */
void RCC_Clock_HAL_Reset(int peripheral_id);

/**
 * Returns the status of a peripheral clock.
 * @param peripheral_id: peripheral type that correlates to a bit location within
 * the RCC registers.
 */
int RCC_Clock_HAL_Status(int peripheral_id);

/**
 * Writes to an RCC register.
 * @param register_address: physical address of the register.
 * @param write_value: value to write to the register.
 */

void RCC_Clock_HAL_Write_Reg(uint32_t *register_address, uint32_t write_value);

/**
 * Retrieves and returns the value of a register.
 * @param register_address: physical address of the register.
 */
uint32_t RCC_Clock_HAL_Read_Reg(uint32_t *register_address);

/***END OF FILE***************************************************************/
