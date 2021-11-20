#include "stm32f411xx_gpio_driver.h"

/* init / deinit GPIO*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0; // tmp register

	// configure mode of gpio pin
if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->MODER |= temp;
	temp = 0;
}else
{

}
	//configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	//configure pupd
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	//configure optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	//configure alt fn
if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
	uint8_t temp1div = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	uint8_t temp2moddiv = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
	pGPIOHandle->pGPIOx->AFR[temp1div] &= ~(0xF << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->AFR[temp1div] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinALtFunMode << (4 * temp2moddiv));
	temp = 0;
}



}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

		if(pGPIOx == GPIOA)
		{
		GPIOA_REG_RESET();
		} else if(pGPIOx == GPIOB)
		{
		GPIOB_REG_RESET();
		}else if(pGPIOx == GPIOC)
		{
		GPIOC_REG_RESET();
		}else if(pGPIOx == GPIOD)
		{
		GPIOD_REG_RESET();
		}else if(pGPIOx == GPIOE)
		{
		GPIOE_REG_RESET();
		}else if(pGPIOx == GPIOH)
		{
		GPIOH_REG_RESET();
		};

}

/* clock setup */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI)
{
	if (ENorDI)
	{
		if(pGPIOx == GPIOA)
		{
		GPIOA_PCLK_EN();
		} else if(pGPIOx == GPIOB)
		{
		GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
		GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
		GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
		GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
		GPIOH_PCLK_EN();
		};

	}else
	{
		if(pGPIOx == GPIOA)
			{
			GPIOA_PCLK_DI();
			} else if(pGPIOx == GPIOB)
			{
			GPIOB_PCLK_DI();
			}else if(pGPIOx == GPIOC)
			{
			GPIOC_PCLK_DI();
			}else if(pGPIOx == GPIOD)
			{
			GPIOD_PCLK_DI();
			}else if(pGPIOx == GPIOE)
			{
			GPIOE_PCLK_DI();
			}else if(pGPIOx == GPIOH)
			{
			GPIOH_PCLK_DI();
			};
	}


}
/* GPIO Sets / Resets */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if (Value)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/* Interrupts support */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ERorDI);
void GPIO_IRQHandling(uint8_t PinNumber);
