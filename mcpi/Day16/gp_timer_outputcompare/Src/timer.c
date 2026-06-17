/*
 * timer.c
 *
 *  Created on: Sep 29, 2025
 *      Author: Sunbeam
 */
#include "timer.h"

void TimerInit(void) {
	// GPIO (GPIOD 12-15) config
	// enable GPIO clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	// set mode to alt fn i.e. 10
	GPIOD->MODER |= BV(12*2+1) | BV(13*2+1) | BV(14*2+1) | BV(15*2+1);
	GPIOD->MODER &= ~(BV(12*2) | BV(13*2) | BV(14*2) | BV(15*2));
	// disable pull-up/pull-down resistors
	GPIOD->PUPDR &= ~(BV(12*2) | BV(13*2) | BV(14*2) | BV(15*2) | BV(12*2+1) | BV(13*2+1) | BV(14*2+1) | BV(15*2+1));
	// set alt fn to AF2 (TIM4 Output Channels)
	GPIOD->AFR[1] |= BV(17) | BV(21) | BV(25) | BV(29);

	// Timer (TIM4) config
	//0. Enable Timer peri clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	//1. Select the counter clock ("internal", external, prescaler).
	TIM4->PSC = PR - 1;
	//2. Write the desired data in the TIMx_ARR and TIMx_CCRx registers.
	TIM4->ARR = ARR_VAL - 1;
	TIM4->CCR1 = CCR1_VAL - 1;
	TIM4->CCR2 = CCR2_VAL - 1;
	TIM4->CCR3 = CCR3_VAL - 1;
	TIM4->CCR4 = CCR4_VAL - 1;
	//3. Set the CCxIE and/or CCxDE bits if an interrupt and/or a DMA request is to be generated.
	// Not using Interrupt and DMA.
	//4. Select the output mode. For example, the user must write OCxM=011, OCxPE=0, CCxP=0 and CCxE=1
	//to toggle OCx output pin when CNT matches CCRx, CCRx preload is not used, OCx is enabled and active high.
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1;
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC4M_0 | TIM_CCMR2_OC4M_1;

	TIM4->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E;
	//5. Enable the counter by setting the CEN bit in the TIMx_CR1 register.
	TIM4->CR1 |= TIM_CR1_CEN;
}
