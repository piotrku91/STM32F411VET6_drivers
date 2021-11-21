#ifndef INC_STM32F411XX_GPIO_DRIVER_H_
#define INC_STM32F411XX_GPIO_DRIVER_H_

#include "stm32f411xx.h"

/* #####################  GPIO configuration structure #####################  */
typedef struct
{
	uint8_t GPIO_PinNumber; /* <possible values from @GPIO_PIN_NO */
	uint8_t GPIO_PinMode; /* <possible values from @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed; /* <possible values from @GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl ; /* <possible values from @GPIO_PIN_PUPD */
	uint8_t GPIO_PinOPType; /* <possible values from @GPIO_PIN_OP_TYPE */
	uint8_t GPIO_PinALtFunMode; /* <possible values from @GPIO_PIN_PUPD */

}GPIO_PinConfig_t;

/* #####################  Handle structure for a GPIO PIN #####################  */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;

/* #####################  GPIO Pin possible pin numbers ##################### @GPIO_PIN_NO  */
#define GPIO_PIN_NO_0									    0
#define GPIO_PIN_NO_1									    1
#define GPIO_PIN_NO_2 										2
#define GPIO_PIN_NO_3 										3
#define GPIO_PIN_NO_4 			 			  	      	    4
#define GPIO_PIN_NO_5 										5
#define GPIO_PIN_NO_6								     	6
#define GPIO_PIN_NO_7									    7
#define GPIO_PIN_NO_8 										8
#define GPIO_PIN_NO_9 										9
#define GPIO_PIN_NO_10 			 			  	      	    10
#define GPIO_PIN_NO_11 										11
#define GPIO_PIN_NO_12								     	12
#define GPIO_PIN_NO_13 			 			  	      	    13
#define GPIO_PIN_NO_14 										14
#define GPIO_PIN_NO_15								     	15

/* #####################  GPIO Pin possible modes ##################### @GPIO_PIN_MODES  */
#define GPIO_MODE_IN 										0
#define GPIO_MODE_OUT									    1
#define GPIO_MODE_ALTFN 									2
#define GPIO_MODE_ANALOG 									3
#define GPIO_MODE_IT_FT 			 			  	        4
#define GPIO_MODE_IT_RT 									5
#define GPIO_MODE_IT_RFT 									6

/* #####################  GPIO Pin possible output types ##################### @GPIO_PIN_OP_TYPE  */
#define GPIO_OP_TYPE_PP										0
#define GPIO_OP_TYPE_OD									    1

/* #####################  GPIO Pin possible speeds #####################  @GPIO_PIN_SPEED */
#define GPIO_SPEED_LOW  									0
#define GPIO_SPEED_MEDIUM 									1
#define GPIO_SPEED_FAST 									2
#define GPIO_SPEED_MHIGH 									3

/* #####################  GPIO pin pull down configuration macros ##################### @GPIO_PIN_PUPD  */
#define GPIO_NO_PUPD									    0
#define GPIO_PIN_PU   								        1
#define GPIO_PIN_PD  								        2


/* ##################### API supported by this driver  #####################  */
/* init / deinit GPIO*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* clock setup */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);
/* GPIO Sets / Resets */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* Interrupts support */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t ERorDI);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);



#endif /* INC_STM32F411XX_H_ */
