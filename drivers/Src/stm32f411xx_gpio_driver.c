#include "stm32f411xx_gpio_driver.h"


/* init / deinit GPIO*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* clock setup */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI)
{
	if (ENorDI)
	{
		if(pGPIOx == GPIOA)
		{
		GPIOA_PLCK_EN();
		} else if(pGPIOx == GPIOB)
		{
		GPIOB_PLCK_EN();
		}else if(pGPIOx == GPIOC)
		{
		GPIOC_PLCK_EN();
		}else if(pGPIOx == GPIOD)
		{
		GPIOD_PLCK_EN();
		}else if(pGPIOx == GPIOE)
		{
		GPIOE_PLCK_EN();
		}else if(pGPIOx == GPIOH)
		{
		GPIOH_PLCK_EN();
		};

	}else
	{
		if(pGPIOx == GPIOA)
			{
			GPIOA_PLCK_DI();
			} else if(pGPIOx == GPIOB)
			{
			GPIOB_PLCK_DI();
			}else if(pGPIOx == GPIOC)
			{
			GPIOC_PLCK_DI();
			}else if(pGPIOx == GPIOD)
			{
			GPIOD_PLCK_DI();
			}else if(pGPIOx == GPIOE)
			{
			GPIOE_PLCK_DI();
			}else if(pGPIOx == GPIOH)
			{
			GPIOH_PLCK_DI();
			};
	}


}
/* GPIO Sets / Resets */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* Interrupts support */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ERorDI);
void GPIO_IRQHandling(uint8_t PinNumber);
