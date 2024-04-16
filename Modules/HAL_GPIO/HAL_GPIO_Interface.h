/*****************************************************************************
* Title                 :   HAL GPIO Interface
* Filename              :   HAL_GPIO_Interface.h
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
#ifndef HAL_GPIO_INTERFACE_H_

#define HAL_GPIO_INTERFACE_H_

/*****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "Driver/GPIO_Driver.h"

/*****************************************************************************
 * PREPROCESSOR CONSTANTS
 *****************************************************************************/

/*****************************************************************************
 * TYPE DEFINTIONS
 *****************************************************************************/
typedef enum
{
	PIN_0, //0b 0000 0000 0000 0000 0000 0000 0000 0111
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
} GPIO_pin_num_t;

typedef enum
{
    BIT_0 = 1,
    BIT_1,
    BIT_2,
    BIT_3,
    BIT_4,
    BIT_5,
    BIT_6,
    BIT_7,
    BIT_8,
    BIT_9,
    BIT_10,
    BIT_11,
    BIT_12,
    BIT_13,
    BIT_14,
    BIT_15,
    BIT_16,
    BIT_17,
    BIT_18,
    BIT_19,
    BIT_20,
    BIT_21,
    BIT_22,
    BIT_23,
    BIT_24,
    BIT_25,
    BIT_26,
    BIT_27,
    BIT_28,
    BIT_29,
    BIT_30,
    BIT_31
} port_bit_t;

typedef enum
{
	LOW,
	HIGH
} GPIO_pin_state_t;

typedef enum
{
	ONLY_INPUT = 0b0000UL, //(LOW | LOW),
	SLOWEST = 0b0010UL, //(LOW | HIGH), //max speed 2MHz
	MEDIAN = 0b0001UL, //(HIGH | LOW), //max speed 10MHz
	FASTEST = 0b0011UL //(HIGH | HIGH) //max speed 50MHz
} GPIO_pin_slew_t;

typedef enum
{
	INPUT_FLOAT = 0b0100UL, //(LOW | HIGH),
	INPUT_PULL_DOWN_UP = 0b1000UL, //(HIGH | LOW),
	ANALOG = 0b0010, //(LOW | LOW),
	OUTPUT_OPEN_DRAIN = 0b0110UL, //(LOW | HIGH),
	OUTPUT_PUSH_PULL = 0b1010UL, //(HIGH | LOW),
	ALT_FNCN_PUSH_PULL = 0b1010UL, //(HIGH | LOW),
	ALT_FNCN_OPEN_DRAIN = 0b1110UL //(HIGH | HIGH)
} GPIO_pin_mode_t;

typedef struct
{
	port_num_t port;
	GPIO_pin_num_t pin;
	GPIO_pin_slew_t slew_rate;
	GPIO_pin_mode_t mode;
	GPIO_pin_state_t init_state;
} GPIO_pin_init_t;

/*****************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/
void HAL_GPIO_Pin_Init(GPIO_pin_init_t * config);
void HAL_GPIO_Pin_Mode(port_num_t port, GPIO_pin_num_t pin, GPIO_pin_mode_t pin_mode);
GPIO_pin_state_t HAL_GPIO_Pin_Read(port_num_t port, GPIO_pin_num_t pin);
void HAL_GPIO_Pin_Write(port_num_t port, GPIO_pin_num_t pin, GPIO_pin_state_t value);


#endif

/***END OF FILE***************************************************************/
