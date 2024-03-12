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
#include "../../EC_PSD_STM32F103_HAL.c"

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

typedef enum
{
	div_2 = 0b000,
	div_4 = 0b001,
	div_8 = 0b010,
	div_16 = 0b011,
	div_32 = 0b100,
	div_64 = 0b101,
	div_128 = 0b110,
	div_256 = 0b111
} baud_rate_t;

typedef enum
{
	mode_0 = 0b00,
	mode_1 = 0b01,
	mode_2 = 0b10,
	mode_3 = 0b11
} sck_mode_t;

typedef enum
{
	size_eight = 0b0,
	size_sixteen = 0b1
} data_frame_sz_t;

typedef enum
{
	msb_first = 0b0,
	lsb_first = 0b1
} frame_format_t;

typedef enum
{
	ssm_disabled = 0b0,
	ssm_enabled = 0b1
} ss_sw_manage_t;

typedef enum
{
	slave_config = 0b0,
	master_config = 0b1
} config_selection_t;

typedef enum
{
	spi_disable = 0b0,
	spi_enable = 0b1
} spi_enable_t;

typedef enum
{
	spi_interface_1 = 1,
	spi_interface_2 = 2,
	spi_interface_3 = 3
} interface_t;

typedef struct
{
	baud_rate_t baud_rate;
	sck_mode_t sck_mode;
	data_frame_sz_t data_frame_sz;
	frame_format_t frame_format;
	ss_sw_manage_t ssm_status;
	config_selection_t config_stat;
	spi_enable_t spi_stat;
	spi_interface_t interface_num;
} spi_config;

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
void SPI_HAL_Config_Interface_DMA(spi_config* config);
void SPI_HAL_Config_Interface_Std(spi_config* config);
void SPI_Write_Config(SPI_Interface_Map_Ptr interface_map_ptr, spi_config* config);
void SPI_HAL_Interface_Slave_Select(int slave_port, int slave_pin);
uint16_t SPI_HAL_Interface_Slave_Read(spi_interface_t interface_num);
void SPI_HAL_Interface_Slave_Write(uint16_t data_frame);
uint16_t SPI_HAL_Interface_Rx_Buffer_Stat();
void SPI_HAL_Write_Reg(uint16_t *reg_addr, uint16_t val);
uint16_t SPI_HAL_Read_Reg(uint16_t *reg_addr);

#endif

/***END OF FILE***************************************************************/
