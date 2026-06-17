/*
 * switch.h
 *
 *  Created on: Sep 13, 2025
 *      Author: sunbeam
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include"stm32f407xx.h"

#define BV(n) (1 << (n))

#define GPIOA_ADDR	0x40020000UL

#define SWITCH_CLK_EN	0

typedef struct
{
  __IO uint32_t MODER;    /*Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*Address offset: 0x0C      */
  __IO uint32_t IDR;      /*Address offset: 0x10      */
  __IO uint32_t ODR;      /*Address offset: 0x14      */
  __IO uint32_t BSRR;     /*Address offset: 0x18      */
  __IO uint32_t LCKR;     /*Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*Address offset: 0x20-0x24 */
} MYGPIO_Type;


#define SWITCH_GPIO		((MYGPIO_Type *)GPIOA_ADDR)

#define MODER_ADDR		GPIOA_ADDR + 0x00UL
#define OTYPER_ADDR		GPIOA_ADDR + 0x04UL
#define OSPEEDR_ADDR	GPIOA_ADDR + 0x08UL
#define PUPDR_ADDR		GPIOA_ADDR + 0x0CUL

#define SWITCH_PIN		0

void switch_init(uint8_t pin);
uint8_t switch_status(void);

#endif /* SWITCH_H_ */
