/*******************************************************************************
* Title                 :   Clock Driver Configuration
* Filename              :   Clock_Driver_Config
* Author                :   Austin Pedigo
* Origin Date           :   2024-02-06
* Version               :   1.1.1
* Compiler              :   ARM_EABI_NONE_GCC
* Target                :   STM32F103C8
* Notes                 :   None
********************************/

/*************** SOURCE REVISION LOG *****************************************
*
*    Date    	Version   	  Author       Description
*  2024-01-06   dev 1.1.1   Austin Pedigo  Initial Release.
*
********************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "Clock_Driver.h"

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
RCC_Register_Map_Ptr RCC_register_map_base = ((RCC_Register_Map_Ptr) 0x40021400UL);

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void Driver_Clock_Bit_Write(int rcc_register_id, int bit_pos)
{
	switch(rcc_register_id)
	{
	case(CR):
		RCC_register_map_base->CR |= (1UL << bit_pos);
		break;
	case(CFGR):
		RCC_register_map_base->CFGR |= (1UL << bit_pos);
		break;
	case(CIR):
		RCC_register_map_base->CIR |= (1UL << bit_pos);
		break;
	case(APB2RSTR):
		RCC_register_map_base->APB2RSTR |= (1UL << bit_pos);
		break;
	case(AHBENR):
		RCC_register_map_base->AHBENR |= (1UL << bit_pos);
		break;
	case(APB2ENR):
		RCC_register_map_base->APB2ENR |= (1UL << bit_pos);
		break;
	case(APB1ENR):
		RCC_register_map_base->APB1ENR |= (1UL << bit_pos);
		break;
	case(BDCR):
		RCC_register_map_base->BDCR |= (1UL << bit_pos);
		break;
	case(CSR):
		RCC_register_map_base->CSR |= (1UL << bit_pos);
		break;
	default:
		//TODO: !!invoke error handler
		break;
	}
}

void Driver_Clock_Bit_Clear(int rcc_register_id, int bit_pos)
{
	switch(rcc_register_id)
	{
	case(CR):
		RCC_register_map_base->CR &= ~(1UL << bit_pos);
		break;
	case(CFGR):
		RCC_register_map_base->CFGR &= ~(1UL << bit_pos);
		break;
	case(CIR):
		RCC_register_map_base->CIR &= ~(1UL << bit_pos);
		break;
	case(APB2RSTR):
		RCC_register_map_base->APB2RSTR &= ~(1UL << bit_pos);
		break;
	case(AHBENR):
		RCC_register_map_base->AHBENR &= ~(1UL << bit_pos);
		break;
	case(APB2ENR):
		RCC_register_map_base->APB2ENR &= ~(1UL << bit_pos);
		break;
	case(APB1ENR):
		RCC_register_map_base->APB1ENR &= ~(1UL << bit_pos);
		break;
	case(BDCR):
		RCC_register_map_base->BDCR &= ~(1UL << bit_pos);
		break;
	case(CSR):
		RCC_register_map_base->CSR &= ~(1UL << bit_pos);
		break;
	default:
		//TODO: !!invoke error handler
		break;
	}
}

int Driver_Clock_Bit_Read(int rcc_register_id, int bit_pos)
{
	int bit_val;

	switch(rcc_register_id)
	{
	case(CR):
		if(RCC_register_map_base->CR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(CFGR):
		if(RCC_register_map_base->CFGR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(CIR):
		if(RCC_register_map_base->CIR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(APB2RSTR):
		if(RCC_register_map_base->APB2RSTR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(AHBENR):
		if(RCC_register_map_base->AHBENR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(APB2ENR):
		if(RCC_register_map_base->APB2ENR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(APB1ENR):
		if(RCC_register_map_base->APB1ENR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(BDCR):
		if(RCC_register_map_base->BDCR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	case(CSR):
		if(RCC_register_map_base->CSR & (1UL << bit_pos))
		{
			bit_val = 1;
		}
		else
		{
			bit_val = 0;
		}
		break;
	default:
		//TODO: !!!invoke error handler!!!
		break;
	}

	return bit_val;
}

void Driver_Clock_Reg_Write(uint32_t* register_addr, uint32_t const write_val)
{
	*register_addr = write_val;
}

uint32_t Driver_Clock_Reg_Read(uint32_t* register_addr)
{
	return *register_addr;
}

/*************** END OF FUNCTIONS ***************************************************************************/
