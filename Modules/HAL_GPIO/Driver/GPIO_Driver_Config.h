/*******************************************************************************
* Title                 :   GPIO Driver Configuration
* Filename              :   GPIO_Driver_Config
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
#ifndef STDINT_H_
#include <stdint.h>
#endif
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/
typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
} volatile * const GPIOx_Register_Map_Ptr;

typedef enum
{
	IO_PORT_A,
	IO_PORT_B,
	IO_PORT_C,
	IO_PORT_D,
	IO_PORT_E,
	IO_PORT_F,
	IO_PORT_G
} port_num_t;

typedef enum
{
	CRL,
	CRH,
	IDR,
	ODR,
	BSRR,
	BRR,
	LCKR
} GPIO_reg_id_t;

typedef enum
{
	INPUT,
	OUTPUT
} GPIO_pin_in_out_t;


/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/*************** END OF FUNCTIONS ***************************************************************************/
