/*
 * wdt.h
 *
 *  Created on: Apr 5, 2025
 *      Author: admin
 */

#ifndef WDT_H_
#define WDT_H_

#include "stm32f4xx.h"

#define WDT_LSICLK	32000
#define WDT_PR		256
#define WDT_PR_VAL	6

void WdtInit(uint32_t ms);
void WdtFeed(void);
int IsWdtReset(void);

#endif /* WDT_H_ */
