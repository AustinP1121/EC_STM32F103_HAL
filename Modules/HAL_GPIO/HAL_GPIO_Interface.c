/*******************************************************************************
* Title                 :   HAL GPIO Interface Implementations
* Filename              :   HAL_GPIO_Interface
* Author                :   Austin Pedigo
* Origin Date           :   2024-02-19
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
#include "HAL_GPIO_Interface.h"

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
void HAL_GPIO_Pin_Init(GPIO_pin_init_t * config)
{
	uint32_t pin_config = 0UL;

	uint32_t pin_state = 0UL;

	//works
	pin_config = (config->slew_rate | config->mode);

	//!!write pin_config
	if(config->pin < 8)
	{
		pin_config = (pin_config << (config->pin*4));

		Driver_GPIO_Write_Pin_State(config->port, CRL, pin_config);
	}
	else if(config->pin > 7)
	{
		pin_config = (pin_config << ((config->pin-8)*4));
		Driver_GPIO_Write_Pin_State(config->port, CRH, pin_config);
	}

	if(config->init_state == HIGH)
	{
		pin_state |= (1UL << config->pin);
		Driver_GPIO_Write_Pin_Output(config->port, pin_state);
	}
	else if(config->init_state == LOW)
	{
		Driver_GPIO_Clear_Pin_Output(config->port, config->pin);
	}
}

GPIO_pin_state_t HAL_GPIO_Pin_Read(port_num_t port, GPIO_pin_num_t pin)
{
	GPIO_pin_state_t pin_value;

	uint32_t reg_value = Driver_GPIO_Read_Input(port);

	if(reg_value & (1UL << pin))
	{
		pin_value = HIGH;
	}
	else
	{
		pin_value = LOW;
	}

	return pin_value;
}

void HAL_GPIO_Pin_Write(port_num_t port, GPIO_pin_num_t pin, GPIO_pin_state_t value)
{
	if(value == HIGH)
	{
		Driver_GPIO_Write_Pin_Output(port, pin);
	}
	else if(value == LOW)
	{
		Driver_GPIO_Clear_Pin_Output(port, pin);
	}
}

/*************** END OF FUNCTIONS ***************************************************************************/
