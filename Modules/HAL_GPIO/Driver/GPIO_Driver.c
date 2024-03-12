/*******************************************************************************
* Title                 :   GPIO Driver
* Filename              :   GPIO_Driver
* Author                :   Austin Pedigo
* Origin Date           :   2024-02-19
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
#include "GPIO_Driver.h"

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

GPIOx_Register_Map_Ptr port_a_map_ptr = ((GPIOx_Register_Map_Ptr)0x40010800UL);
GPIOx_Register_Map_Ptr port_b_map_ptr = ((GPIOx_Register_Map_Ptr)0x40010C00UL);
GPIOx_Register_Map_Ptr port_c_map_ptr = ((GPIOx_Register_Map_Ptr)0x40011000UL);
GPIOx_Register_Map_Ptr port_d_map_ptr = ((GPIOx_Register_Map_Ptr)0x40011400UL);
GPIOx_Register_Map_Ptr port_e_map_ptr = ((GPIOx_Register_Map_Ptr)0x40011800UL);
GPIOx_Register_Map_Ptr port_f_map_ptr = ((GPIOx_Register_Map_Ptr)0x40011C00UL);
GPIOx_Register_Map_Ptr port_g_map_ptr = ((GPIOx_Register_Map_Ptr)0x40012000UL);

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void Driver_GPIO_Write_Pin_State(port_num_t port, GPIO_reg_id_t reg_id, uint32_t value)
{
	switch(port)
	{
	case IO_PORT_A:
		if(reg_id == CRL)
		{
			port_a_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_a_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_B:
		if(reg_id == CRL)
		{
			port_b_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_b_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_C:
		if(reg_id == CRL)
		{
			port_c_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_c_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_D:
		if(reg_id == CRL)
		{
			port_d_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_d_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_E:
		if(reg_id == CRL)
		{
			port_e_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_e_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_F:
		if(reg_id == CRL)
		{
			port_f_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_f_map_ptr->CRH = value;
		}
		break;
	case IO_PORT_G:
		if(reg_id == CRL)
		{
			port_g_map_ptr->CRL = value;
		}
		else if(reg_id == CRH)
		{
			port_g_map_ptr->CRH = value;
		}
		break;
	default:
		break;
	}
}

void Driver_GPIO_Write_Pin_Output(port_num_t port, uint32_t value)
{
	switch(port)
	{
	case IO_PORT_A:
		port_a_map_ptr->ODR |= value;
		break;
	case IO_PORT_B:
		port_b_map_ptr->ODR |= value;
		break;
	case IO_PORT_C:
		port_c_map_ptr->ODR |= value;
		break;
	case IO_PORT_D:
		port_d_map_ptr->ODR |= value;
		break;
	case IO_PORT_E:
		port_e_map_ptr->ODR |= value;
		break;
	case IO_PORT_F:
		port_f_map_ptr->ODR |= value;
		break;
	case IO_PORT_G:
		port_g_map_ptr->ODR |= value;
		break;
	default:
		break;
	}
}

void Driver_GPIO_Clear_Pin_Output(port_num_t port, uint32_t value)
{
	switch(port)
	{
	case IO_PORT_A:
		port_a_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_B:
		port_b_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_C:
		port_c_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_D:
		port_d_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_E:
		port_e_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_F:
		port_f_map_ptr->ODR &= ~(1UL << value);
		break;
	case IO_PORT_G:
		port_g_map_ptr->ODR &= ~(1UL << value);
		break;
	default:
		break;
	}
}


uint32_t Driver_GPIO_Read_Input(port_num_t port)
{
	//init value
	uint32_t reg_value = 0;

	switch(port)
	{
	case IO_PORT_A:
		reg_value = port_a_map_ptr->IDR;
		break;
	case IO_PORT_B:
		reg_value = port_b_map_ptr->IDR;
		break;
	case IO_PORT_C:
		reg_value = port_c_map_ptr->IDR;
		break;
	case IO_PORT_D:
		reg_value = port_d_map_ptr->IDR;
		break;
	case IO_PORT_E:
		reg_value = port_e_map_ptr->IDR;
		break;
	case IO_PORT_F:
		reg_value = port_f_map_ptr->IDR;
		break;
	case IO_PORT_G:
		reg_value = port_g_map_ptr->IDR;
		break;
	default:
		break;
	}

	return reg_value;
}

/******************************************************************************
* Function Definitions
*******************************************************************************/

/*************** END OF FUNCTIONS ***************************************************************************/
