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
*    Date    Version   Author         Description
*  2024-01-06   dev 1.1.1   Austin Pedigo  Initial Release.
*
********************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../HAL_Clock_Interface.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/**
 * Lays out each register in the Reset and Clock Control (RCC) space.
 *
 * Each register is 32 bits wide.
 * */
typedef struct {
	uint32_t CR; /**<Control Register */
	uint32_t CFGR; /**<Configuration Register */
	uint32_t CIR; /**<Interrupt Register */
	uint32_t APB2RSTR; /**<APB2 Peripheral Reset Register */
	uint32_t APB1RSTR; /**<APB1 Peripheral Reset Register */
	uint32_t AHBENR; /**<AHB Peripheral Clock Enable Register */
	uint32_t APB2ENR; /**<APB2 Peripheral Clock Enable Register */
	uint32_t APB1ENR; /**<APB1 Peripheral Clock Enable Register */
	uint32_t BDCR; /**<Backup Domain Control Register */
	uint32_t CSR; /**<Control/Status Register */
} volatile * const RCC_Register_Map_Ptr;

/**
 * RCC Register IDs
 * */
enum{
	CR,
	CFGR,
	CIR,
	APB2RSTR,
	APB1RSTR,
	AHBENR,
	APB2ENR,
	APB1ENR,
	BDCR,
	CSR
};

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/*************** END OF FUNCTIONS ***************************************************************************/
