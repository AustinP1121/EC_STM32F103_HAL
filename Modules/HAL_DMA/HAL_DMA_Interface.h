/****************************************************************************
* Title                 :   DMA HAL Module
* Filename              :   HAL_DMA_Interface.h
* Author                :   Austin Pedigo
* Origin Date           :   2024-02-27
* Version               :   1.0.0
* Compiler              :
* Target                :
* Notes                 :   None
*****************************************************************************/
#ifndef HAL_DMA_INTERFACE_H_
#define HAL_DMA_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

#include "../../EC_PSD_STM32F103_HAL.c"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/
#define DMA1_BASE_ADDR 		0x40020000UL
#define DMA1_CHANNEL_1_ADDR 	(DMA1_BASE_ADDR + 0x008UL)
#define DMA1_CHANNEL_2_ADDR		(DMA1_BASE_ADDR + 0x01CUL)
#define DMA1_CHANNEL_3_ADDR		(DMA1_BASE_ADDR + 0x030UL)
#define DMA1_CHANNEL_4_ADDR		(DMA1_BASE_ADDR + 0x044UL)
#define DMA1_CHANNEL_5_ADDR		(DMA1_BASE_ADDR + 0x058UL)
#define DMA1_CHANNEL_6_ADDR		(DMA1_BASE_ADDR + 0x06CUL)
#define DMA1_CHANNEL_7_ADDR		(DMA1_BASE_ADDR + 0x080UL)

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct
{
	uint32_t ISR;
	uint32_t IFCR;
} volatile * const DMA_Channel_Config_Map_Ptr;

typedef struct
{
	uint32_t CCRx;
	uint32_t CNDTRx;
	uint32_t CPARx;
	uint32_t CMARx;
} volatile * const DMA_Channel_X_Map_Ptr;

typedef enum
{
	low = 0b00,
	medium = 0b01,
	high = 0b10,
	very_high = 0b11
} channel_priority_t;

typedef enum
{
	send_data = 0b0,
	receive_data = 0b1
} data_dir_t;

typedef enum
{
	circular_mode,
	mem_mem_mode
} data_acq_mode_t;

typedef enum
{
	eight_bit = 0b00,
	sixteen_bit = 0b01,
	thirty_two_bit = 0b10
} mem_size_t;

typedef enum
{
	channel_1,
	channel_2,
	channel_3,
	channel_4,
	channel_5,
	channel_6,
	channel_7
} dma_channel_t;

typedef struct {
	dma_channel_t channel;
	uint32_t peripheral_addr;
	uint32_t second_source_addr;
	uint16_t data_count;
	channel_priority_t channel_priority;
	data_dir_t data_direction;
	data_acq_mode_t data_acq_mode;
	mem_size_t periph_mem_size;
	mem_size_t memory_mem_size;

} dma_config_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void DMA_HAL_Config_Channel(dma_config_t * config);
void DMA_HAL_Disable_Channel(dma_channel_t channel_num);
void DMA_HAL_Write_Reg(uint32_t * reg_addr, const uint32_t value);
uint32_t DMA_HAL_Read_Reg(const uint32_t * reg_addr);

void DMA_Write_Channel(DMA_Channel_X_Map_Ptr dma_ptr_map, dma_config_t * config);

#endif

/*** End of File **************************************************************/
