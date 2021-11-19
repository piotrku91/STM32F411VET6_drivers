/*
 * stm32f411xx.h
 *
 *  Created on: Nov 19, 2021
 *      Author: piotrq
 */

#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#include <stdint.h>
#define __vo volatile

#define FLASH_BASEADDR              0x80000000U /* Flash memory main address */
#define SRAM1_BASEADDR			    0x20000000U /* SRAM memory main address */
#define ROM	                        0x1FFF0000  /* ROM memory main address */
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
}GPIO_RefDef_t;

/*  ###################### peripherals definitions   #####################*/
#define GPIOA 						((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 						((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 						((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 						((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE						((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH 						((GPIO_RegDef_t*)GPIOH_BASEADDR)


#endif /* INC_STM32F411XX_H_ */
