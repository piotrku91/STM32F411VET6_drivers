/*
 * stm32f411xx.h
 *
 *  Created on: Nov 19, 2021
 *      Author: piotrq
 */

#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#include <stdint.h>
#include <stdio.h>

/* Generally macros */
#define __vo volatile
#define ENABLE						1
#define DISABLE    					0
#define SET							ENABLE
#define RESET						DISABLE
#define GPIO_PIN_SET                SET
#define GPIO_PIN_RESET				RESET

/* Processor Cortex Mx NVIC ISERx & ICERx Registers Addresses */
#define NVIC_ISER0					((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1					((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2					((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3					((__vo uint32_t*)0xE000E10C)
#define NVIC_ICER0					((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1					((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2					((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3					((__vo uint32_t*)0xE000E18C)

/* Processor Cortex Mx NVIC priority Register Addresses */
#define NVIC_PR_BASEADDR				((__vo uint32_t*)0xE000E400)




/*IRQ Numbbers for STM32F411xC/E */
#define IRQ_NO_EXTI0				6
#define IRQ_NO_EXTI1				7
#define IRQ_NO_EXTI2				8
#define IRQ_NO_EXTI3				9
#define IRQ_NO_EXTI4				10
#define IRQ_NO_EXTI9_5				23
#define IRQ_NO_EXTI15_10			40
#define IRQ_NO_EXTI16				1
#define IRQ_NO_EXTI21				2
#define IRQ_NO_EXTI22				3
#define IRQ_NO_EXTI17				41
#define IRQ_NO_EXTI18				42


#define FLASH_BASEADDR              0x80000000U /* Flash memory main address */
#define SRAM1_BASEADDR			    0x20000000U /* SRAM memory main address */
#define ROM	                        0x1FFF0000U  /* ROM memory main address */
#define SRAM 						SRAM1_BASEADDR

/* APB and AHB Bus peripherals addresses */

#define PERIPH_BASE 				0x40000000U
#define APB1PERIPH_BASE	       	    PERIPH_BASE
#define APB2PERIPH_BASE				0x40010000U
#define AHB1PERIPH_BASE				0x40020000U
#define AHB2PERIPH_BASE				0x50000000U


/* Base addresses of peripherals are hanging AHB1 bus */

#define GPIOA_BASEADDR 				(AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR 				(AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR 				(AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR 				(AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR 				(AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASEADDR 				(AHB1PERIPH_BASE + 0x1C00)
#define RCC_BASEADDR 				(AHB1PERIPH_BASE + 0x3800)

/* Base addresses of peripherals are hanging APB1 bus */

#define I2C1_BASEADDR 				(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR 				(APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR 				(APB1PERIPH_BASE + 0x5C00)
#define SPI2_BASEADDR 				(APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR 				(APB1PERIPH_BASE + 0x3C00)
#define USART2_BASEADDR 			(APB1PERIPH_BASE + 0x4400)

/* Base addresses of peripherals are hanging APB2 bus */

#define EXTI_BASEADDR 				(APB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR 			(APB2PERIPH_BASE + 0x3800)
#define SPI1_BASEADDR 				(APB2PERIPH_BASE + 0x3000)
#define SPI4_BASEADDR 				(APB2PERIPH_BASE + 0x3400)
#define SPI5_BASEADDR 				(APB2PERIPH_BASE + 0x5000)
#define USART1_BASEADDR 			(APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR 			(APB2PERIPH_BASE + 0x1400)

/* Clock Enable Macros for GPIOx peripherals */

#define GPIOA_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN() 			(RCC->AHB1ENR |= (1 << 7))

/* Clock Enable Macros for i2C peripherals */

#define I2C1_PCLK_EN() 				(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() 				(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() 				(RCC->APB1ENR |= (1 << 23))

/* Clock Enable Macros for SPI peripherals */

#define SPI1_PCLK_EN() 				(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() 				(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() 				(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() 				(RCC->APB2ENR |= (1 << 13))
#define SPI5_PCLK_EN() 				(RCC->APB2ENR |= (1 << 20))

/* Clock Enable Macros for USART peripherals */

#define USART2_PCLK_EN() 			(RCC->APB1ENR |= (1 << 17))
#define USART1_PCLK_EN() 			(RCC->APB2ENR |= (1 << 4))
#define USART6_PCLK_EN() 			(RCC->APB2ENR |= (1 << 7))

/* Clock Enable Macros for SYSCFG peripheral */

#define SYSCFG_PCLK_EN() 			(RCC->APB2ENR |= (1 << 14))

/* Clock Disable Macros for SYSCFG peripheral */

#define SYSCFG_PCLK_DI() 			(RCC->APB2ENR &= ~(1 << 14))


/* Clock Disable Macros for GPIOx peripherals */

#define GPIOA_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI() 			(RCC->AHB1ENR &= ~(1 << 7))

/* RESET GPIOx peripherals */

#define GPIOA_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOH_REG_RESET() 			do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));}while(0)

/* GPIO to code converter */
#define GPIO_BASEADDR_TO_CODE(x) 	((x == GPIOA)? 0:\
									(x == GPIOB)? 1:\
									(x == GPIOC)? 2:\
									(x == GPIOD)? 3:\
									(x == GPIOE)? 4:\
									(x == GPIOH)? 7:0)


/* Clock Disable Macros for SPI peripherals */

#define SPI1_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 13))
#define SPI5_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 20))

/* Clock Disable Macros for USART peripherals */

#define USART2_PCLK_DI() 			(RCC->APB1ENR &= ~(1 << 17))
#define USART1_PCLK_DI() 			(RCC->APB2ENR &= ~(1 << 4))
#define USART6_PCLK_DI() 			(RCC->APB2ENR &= ~(1 << 7))


/*  ###################### peripherals register definition structures  #####################*/

typedef struct
{
	__vo uint32_t MODER;     /* GPIO port mode register  */
	__vo uint32_t OTYPER;	/*  GPIO port output type register */
	__vo uint32_t OSPEEDR;	/*  GPIO port output speed register  */
	__vo uint32_t PUPDR; 	/* GPIO port pull-up/pull-down register  */
	__vo uint32_t IDR; /* GPIO port input data register  */
	__vo uint32_t ODR; /* GPIO port output data register  */
	__vo uint32_t BSRR; /*  GPIO port bit set/reset register */
	__vo uint32_t LCKR; /* GPIO port configuration lock register  */
	__vo uint32_t AFR[2]; /* GPIO alternate function low register / GPIO alternate function high register  */
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t IMR;     /* Interrupt mask register  */
	__vo uint32_t EMR;	/*  Event mask register */
	__vo uint32_t RTSR;	/*  Rising trigger selection register  */
	__vo uint32_t FTSR; 	/* Falling trigger selection register  */
	__vo uint32_t SWIER; /* Software interrupt event register  */
	__vo uint32_t PR; /* Pending register  */
}EXTI_RegDef_t;


typedef struct
{
	__vo uint32_t MEMRMP;     /* SYSCFG memory remap register  */
	__vo uint32_t PMC;	/*  SYSCFG peripheral mode configuration register */
	__vo uint32_t EXTICR[4];	/*  SYSCFG external interrupt configuration register 1  */
	__vo uint32_t CMPCR; /* Compensation cell control register  */
}SYSCFG_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CCIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	 uint32_t RESERVED0[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	uint32_t RESERVED2[2];
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED4[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	uint32_t RESERVED7[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t DCKCFGR;

}RCC_RegDef_t;

/*  ###################### peripherals definitions   #####################*/
#define GPIOA 						((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 						((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 						((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 						((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE						((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH 						((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC 						((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI 						((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG						((SYSCFG_RegDef_t*)RCC_BASEADDR)


#include "stm32f411xx_gpio_driver.h"

#endif /* INC_STM32F411XX_H_ */
