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
AFIO_Map_Ptr AFIO_Map = ((AFIO_Map_Ptr)(0x40010000UL));

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
	//remap SPI1 to PB3, PB4, PB5
    AFIO_Map->MAPR |= (1UL << 0);

    //set SWJ_CFG[2:0] to 0b111
    AFIO_Map->MAPR |= (1UL << 25);
    AFIO_Map->MAPR |= (1UL << 26);
    AFIO_Map->MAPR |= (1UL << 27);

	//alternate function mode for SPI
	GPIO_pin_init_t sck_pin;
	GPIO_pin_init_t miso_pin;
	GPIO_pin_init_t mosi_pin;

	//configure the SCK pin
	sck_pin.pin = config->sck_pin;
	sck_pin.port = config->port;
	sck_pin.mode = ALT_FNCN_PUSH_PULL;
	sck_pin.slew_rate = FASTEST;
	sck_pin.init_state = HIGH;

	//configure the MISO pin
	miso_pin.pin = config->miso_pin;
	miso_pin.port = config->port;
	//configure as input floating
	miso_pin.mode = INPUT_FLOAT;
	miso_pin.slew_rate = ONLY_INPUT;
	miso_pin.init_state = HIGH;

	//set the pins for the SPI interface
	mosi_pin.pin = config->mosi_pin;
	mosi_pin.port = config->port;
	mosi_pin.mode = ALT_FNCN_PUSH_PULL;
	mosi_pin.slew_rate = FASTEST;
	mosi_pin.init_state = HIGH;

	//initialize the pins
	HAL_GPIO_Pin_Init(&sck_pin);
	HAL_GPIO_Pin_Init(&miso_pin);
	HAL_GPIO_Pin_Init(&mosi_pin);

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

	//write the ssi bit (SSI), SPI_CR1
	interface_map_ptr->CR1 |= (1UL << 8);

	//write the configuration (MSTR), SPI_CR1
	interface_map_ptr->CR1 |= (config->config_stat << 2);

	//enable the spi interface
	interface_map_ptr->CR1 |= (config->spi_stat << 6);
}

void SPI_HAL_Interface_Slave_Select(int slave_port, int slave_pin, int slave_select_state)
{
	GPIO_pin_init_t slave_select_pin;

	slave_select_pin.pin = slave_pin;
	slave_select_pin.port = slave_port;
	slave_select_pin.mode = OUTPUT_PUSH_PULL;
	slave_select_pin.slew_rate = MEDIAN;
	slave_select_pin.init_state = HIGH;

	HAL_GPIO_Pin_Init(&slave_select_pin);

	HAL_GPIO_Pin_Write(slave_port, slave_pin, slave_select_state);
}

uint8_t SPI_HAL_Interface_Slave_Read_8(interface_t interface_num)
{
	uint8_t data_frame;

	switch ((int) interface_num)
	{
	case spi_interface_1:
		//send dummy data
		while (((SPI_1_Map_Ptr->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication
		SPI_1_Map_Ptr->DR = 1;  // send dummy data
		while (!((SPI_1_Map_Ptr->SR) &(1<<0))){};  // Wait for RXNE to set -> This will indicate that the Rx buffer is not empty
		//read the 8 lsb of the data register
		data_frame = (SPI_1_Map_Ptr->DR);
		break;
	case spi_interface_2:
		data_frame = SPI_2_Map_Ptr->DR;
		break;
	case spi_interface_3:
		data_frame = SPI_3_Map_Ptr->DR;
		break;
	default:
		break;
	}

	return data_frame;
}

uint16_t SPI_HAL_Interface_Slave_Read_16(interface_t interface_num)
{
	uint16_t data_frame;

	//wait for the RXE to be available
	while (!SPI_HAL_Interface_Rx_Buffer_Stat(interface_num));

	switch ((int) interface_num) {
	case spi_interface_1:
		data_frame = SPI_1_Map_Ptr->DR;
		break;
	case spi_interface_2:
		data_frame = SPI_2_Map_Ptr->DR;
		break;
	case spi_interface_3:
		data_frame = SPI_3_Map_Ptr->DR;
		break;
	default:
		break;
	}

	return data_frame;
}

void SPI_HAL_Interface_Slave_Write_16(interface_t interface_num, uint16_t data_frame)
{
	//wait for the TXE to be available
	while (!SPI_HAL_Interface_Tx_Buffer_Stat(interface_num));

	switch ((uint32_t) interface_num) {
	case spi_interface_1:

		while (!((SPI_1_Map_Ptr->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		SPI_1_Map_Ptr->DR = data_frame;  // load the data into the Data Register

		while (!((SPI_1_Map_Ptr->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		while (((SPI_1_Map_Ptr->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication

			//  Clear the Overrun flag by reading DR and SR
		uint8_t temp = SPI_1_Map_Ptr->DR;
		temp = SPI_1_Map_Ptr->SR;
		break;
	case spi_interface_2:
		SPI_2_Map_Ptr->DR = data_frame;
		break;
	case spi_interface_3:
		SPI_3_Map_Ptr->DR = data_frame;
		break;
	default:
		break;
	}
}

void SPI_HAL_Interface_Slave_Write_8(interface_t interface_num, uint8_t data_frame)
{
	//wait for the TXE to be available
	while (!SPI_HAL_Interface_Tx_Buffer_Stat(interface_num));

	switch ((uint32_t) interface_num) {
	case spi_interface_1:
		while (!((SPI_1_Map_Ptr->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		SPI_1_Map_Ptr->DR = data_frame;  // load the data into the Data Register

		while (!((SPI_1_Map_Ptr->SR)&(1<<1))) {};  // wait for TXE bit to set -> This will indicate that the buffer is empty
		while (((SPI_1_Map_Ptr->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication

			//  Clear the Overrun flag by reading DR and SR
		uint8_t temp = SPI_1_Map_Ptr->DR;
		temp = SPI_1_Map_Ptr->SR;
		break;
	case spi_interface_2:
		SPI_2_Map_Ptr->DR = data_frame;
		break;
	case spi_interface_3:
		SPI_3_Map_Ptr->DR = data_frame;
		break;
	default:
		break;
	}
}


uint32_t SPI_HAL_Interface_Rx_Buffer_Stat(spi_interface_t interface_num)
{
	uint32_t status = 0;

	uint32_t RXE_Full = 1;
	uint32_t RXE_Avail = (1UL << 0);

	switch((int)interface_num)
	{
	case spi_interface_1:
		if(SPI_1_Map_Ptr->SR & RXE_Avail)
		{
			status = RXE_Full;
		}
		break;
	case spi_interface_2:
		if(SPI_2_Map_Ptr->SR & RXE_Avail)
		{
			status = RXE_Full;
		}
		break;
	case spi_interface_3:
		if(SPI_3_Map_Ptr->SR & RXE_Avail)
		{
			status = RXE_Full;
		}
		break;
	default:
		break;
	}

	return status;
}

uint32_t SPI_HAL_Interface_Tx_Buffer_Stat(spi_interface_t interface_num)
{
	uint32_t status = 0;

	uint32_t TXE_Full = 1;
	uint32_t TXE_Avail = (1UL << 1);

	switch ((uint32_t) interface_num) {
	case spi_interface_1:
		//check if the TXE is ready
		if (SPI_1_Map_Ptr->SR & TXE_Avail) {
			status = TXE_Full;
		}
		break;
	case spi_interface_2:
		if (SPI_2_Map_Ptr->SR & TXE_Avail) {
			status = TXE_Full;
		}
		break;
	case spi_interface_3:
		if (SPI_3_Map_Ptr->SR & TXE_Avail) {
			status = TXE_Full;
		}
		break;
	default:
		break;
	}

	return status;
}

void SPI_HAL_Write_Reg(uint32_t *reg_addr, uint32_t val)
{
	*reg_addr = val;
}

uint32_t SPI_HAL_Read_Reg(uint32_t *reg_addr)
{
    uint32_t reg_val = *reg_addr;

	return reg_val;
}

void SPI_HAL_DMA_Transmit(interface_t interface_num,
		uint32_t *tx_buf,
		uint32_t buffer_size)
{

}
void SPI_HAL_DMA_Receive(interface_t interface_num,
		uint32_t *rx_buf,
		uint32_t buffer_size)
{

}

/*************** END OF FUNCTIONS ***************************************************************************/






