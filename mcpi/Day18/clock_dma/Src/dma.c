#include "dma.h"

void DMA_Init(void) {
    // 1. Enable the clock for the DMA2 controller in the RCC peripheral.
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    // 2. Configure and enable the DMA stream's interrupt in the NVIC.
    // This allows us to get a callback when the transfer is complete.
    NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

void DMA_Mem_Transfer(uint8_t *dma_mem_dst, uint8_t *dma_mem_src, uint16_t size) {
    // clear DMA Stream configuration register
    // single transfer, M0 is target, single buffer mode, circular buffer disabled
    // Make sure the stream is disabled before configuring it.
    DMA2_Stream0->CR = 0x0000;
    while(DMA2_Stream0->CR & DMA_SxCR_EN); // Wait until it's truly disabled

    // Set the source memory address
    DMA2_Stream0->PAR = (uint32_t)dma_mem_src;

    // Set the destination memory address
    DMA2_Stream0->M0AR = (uint32_t)dma_mem_dest;

    // In M2M mode, PAR is used as the destination

    // Set the number of data items to transfer
    DMA2_Stream0->NDTR = size;

    // Configure the Control Register (CR) for the stream
    DMA2_Stream0->CR |= (0 << DMA_SxCR_CHSEL_Pos); // Channel 0 for M2M
    DMA2_Stream0->CR |= DMA_SxCR_MINC;             // Increment Memory address
    DMA2_Stream0->CR |= DMA_SxCR_PINC;             // Increment "Peripheral" (destination memory) address
    DMA2_Stream0->CR |= (0 << DMA_SxCR_MSIZE_Pos);  // Memory data size: byte
    DMA2_Stream0->CR |= (0 << DMA_SxCR_PSIZE_Pos);  // Peripheral data size: byte
    DMA2_Stream0->CR |= DMA_SxCR_PL_1;             // Priority: High
    DMA2_Stream0->CR |= DMA_SxCR_TCIE;             // Enable Transfer Complete Interrupt

    // Enable the stream to arm it for the transfer.
    // Since this is M2M, the transfer starts immediately.
    DMA2_Stream0->CR |= DMA_SxCR_EN;
}

// The Interrupt Service Routine for DMA2 Stream 0
volatile int dma2_flag = 0;
void DMA2_Stream0_IRQHandler(void) {
    // Check if the Transfer Complete Interrupt Flag is set
    if(DMA2->LISR & DMA_LISR_TCIF0) {
        // Clear the flag to prevent re-entering the ISR
        DMA2->LIFCR |= DMA_LIFCR_CTCIF0;
        // flag the interrupt
        dma2_flag = 1;
    }
}
