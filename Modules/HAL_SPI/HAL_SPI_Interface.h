/*****************************************************************************
* Title                 :   HAL SPI Interface
* Filename              :   HAL_SPI_Interface.h
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
#ifndef HAL_SPI_INTERFACE_H_

#define HAL_SPI_INTERFACE_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/

/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/
typedef struct
{
	uint16_t CR1;
	uint16_t CR2;
	uint16_t SR;
	uint16_t DR;
	uint16_t CRCPR;
	uint16_t RXCRCR;
	uint16_t TXCRCR;
	uint16_t I2SCFGR;
	uint16_t I2SPR;
} volatile * const SPI_Interface_Map_Ptr;

typedef struct
{

} spi_config;


/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
SPI_HAL_Config_Interface_DMA(spi_config* config);
SPI_HAL_Config_Interface_
#endif

/***END OF FILE***************************************************************/
