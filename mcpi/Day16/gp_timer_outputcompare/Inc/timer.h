/*
 * timer.h
 *
 *  Created on: Sep 29, 2025
 *      Author: Sunbeam
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

#define FPLCK 16000000UL
#define PR	  16000

#define ARR_VAL		500
#define CCR1_VAL	100
#define CCR2_VAL	200
#define CCR3_VAL	300
#define CCR4_VAL	400

void TimerInit(void);

#endif /* TIMER_H_ */
