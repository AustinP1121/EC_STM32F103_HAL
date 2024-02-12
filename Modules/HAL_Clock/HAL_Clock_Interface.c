/*******************************************************************************
* Title                 :   HAL Clock Interface Implementations
* Filename              :   HAL_Clock_Interface
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
#include "HAL_Clock_Interface.h"
#include "Driver/Clock_Driver.h"

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

void RCC_Clock_HAL_Enable(int peripheral_id)
{
	//enable peripheral clock via driver function call
	Driver_Clock_Bit_Write();

}

void RCC_Clock_HAL_Disable(int peripheral_id)
{

}

void RCC_Clock_HAL_Reset(int peripheral_id)
{

}

int RCC_Clock_HAL_Status(int peripheral_id)
{
	return 0;
}

void RCC_Clock_HAL_Write_Reg(uint32_t *register_address, uint32_t write_value)
{

}

uint32_t RCC_Clock_HAL_Read_Reg(uint32_t *register_address)
{
	return 0;
}

/*************** END OF FUNCTIONS ***************************************************************************/






