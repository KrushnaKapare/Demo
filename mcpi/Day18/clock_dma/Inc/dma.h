/*
 * dma.h
 *
 *  Created on: Apr 11, 2024
 *      Author: Nilesh
 */

#ifndef DMA_H_
#define DMA_H_

#include "stm32f4xx.h"

void DMA_Init(void);
void DMA_Mem_Transfer(uint8_t *dma_mem_dst, uint8_t *dma_mem_src, uint16_t size);
extern volatile int dma2_flag;

#endif /* DMA_H_ */
