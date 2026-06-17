/*
 * timer.c
 *
 *  Created on: Sep 29, 2025
 *      Author: Sunbeam
 */

#include "timer.h"

void TimerInit(void) {
	// Enable Timer APB clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	// Set the Prescalar
	TIM6->PSC = PR - 1;
}

void TimerDelayMs(uint32_t ms) {
	// calculate number of clocks to count
	uint32_t cnt = (FPCLK / 1000) * ms / PR;
	// set max count in ARR
	TIM6->ARR = cnt - 1;
	// start counting from zero
	TIM6->CNT = 0;
	// enable timer clock (mandatory) and set APRE (optional)
	TIM6->CR1 |= TIM_CR1_CEN;
	// wait for update event SR -- UIF flag
	while(!(TIM6->SR & TIM_SR_UIF));
	// clear update flag in SR
	TIM6->SR &= ~TIM_SR_UIF;
	// stop timer clock
	TIM6->CR1 &= ~TIM_CR1_CEN;
}

