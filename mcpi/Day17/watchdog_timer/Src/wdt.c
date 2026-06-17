/*
 * wdt.c
 *
 *  Created on: Apr 5, 2025
 *      Author: admin
 */

#include "wdt.h"

void WdtInit(uint32_t ms) {
	//- step 0. Enable LSI clock and wait until LSI is ready
	RCC->CSR |= RCC_CSR_LSION;
	while(!(RCC->CSR & RCC_CSR_LSIRDY))
		;
	//- step 1. Enable IWDG by writing 0xCCCC into IWDG_KR.
	IWDG->KR = 0xCCCC;
	//- step 2. Enable register access by writing 0x5555 into IWDG_KR.
	IWDG->KR = 0x5555;
	//- step 3. Set Prescalar value in IWDG_PR.
	IWDG->PR = WDT_PR_VAL;
	//- step 4. Set Reload value in IWDG_RLR.
	uint32_t cnt = (WDT_LSICLK / 1000) * ms / WDT_PR;
	IWDG->RLR = cnt - 1;
	//- step 5. Wait for registers to be updated i.e. IWDG_SR == 0x00000000;
	while(IWDG->SR != 0)
		;
	//- Feed watchdog
	WdtFeed();
}

void WdtFeed(void) {
    //- step 6. Refresh counter by writing 0xAAAA into IWDG_KR.
	IWDG->KR = 0xAAAA;
}

int IsWdtReset(void) {
    //- step 7. If reset due to IWDG, Bit 29 in RCC_CSR is set. Check the bit immediately after initialization and report the error.
	if((RCC->CSR & RCC_CSR_IWDGRSTF) != 0)
		return 1; // Yes, Reset due to WDT
	return 0; // Reset NOT due to WDT
}
