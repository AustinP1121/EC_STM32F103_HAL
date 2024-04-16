/*****************************************************************************
* Title                 :   Clock Driver Header
* Filename              :   Clock_Driver.h
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
#ifndef GPIO_DRIVER_H_

#define GPIO_DRIVER_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include <EC_PSD_STM32F103_HAL/Modules/HAL_GPIO/Driver/GPIO_Driver_Config.h>

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/

/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
//writes the pin configuration
void Driver_GPIO_Write_Pin_Cnf(port_num_t port,
		GPIO_reg_id_t reg_id,
		uint32_t value,
		uint32_t pin);
//writes to and returns the output data reg
void Driver_GPIO_Write_Pin_Output(port_num_t port, uint32_t value);
//clears the output data reg
void Driver_GPIO_Clear_Pin_Output(port_num_t port, uint32_t value);
//grabs input data reg
uint32_t Driver_GPIO_Read_Input(port_num_t port);

#endif

/***END OF FILE***************************************************************/
