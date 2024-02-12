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
#ifndef CLOCK_DRIVER_H_

#define CLOCK_DRIVER_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "Clock_Driver_Config.h"

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/

/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
void Driver_Clock_Bit_Write(int rcc_register_id, int bit_pos);
void Driver_Clock_Bit_Clear(int rcc_register_id, int bit_pos);
int Driver_Clock_Bit_Read(int rcc_register_id, int bit_pos);
void Driver_Clock_Reg_Write(int rcc_register_id, uint32_t const write_val);
uint32_t Driver_Clock_Reg_Read(int rcc_register_id);

#endif

/***END OF FILE***************************************************************/
