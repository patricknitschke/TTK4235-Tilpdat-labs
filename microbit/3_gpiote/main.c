#include "gpiote.h"
#include "gpio.h"
#include "ppi.h"
#include <stdio.h>




typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[120];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[26] = 0;
	GPIO->PIN_CNF[17] = 0;

	//GPIOTE
	//litt usikker på om dette er gode greier, men here we go

	GPIO->DIRSET = (1<<0)|(1<<1);
	GPIOTE->CONFIG[0] = (1<<0)|(1<<8)|(1<<12)|(1<<16)|(1<<17); 
	GPIOTE->CONFIG[1] = (1<<0)|(1<<1)|(1<<8)|(1<<10)|(1<<11)|(1<<16)|(1<<17)|(1<<20);
	GPIOTE->CONFIG[2] = (1<<0)|(1<<1)|(1<<9)|(1<<10)|(1<<11)|(1<<16)|(1<<17)|(1<<20);
	GPIOTE->CONFIG[3] = (1<<0)|(1<<1)|(1<<9)|(1<<8)|(1<<10)|(1<<11)|(1<<16)|(1<<17)|(1<<20);

	//PPI
	PPI->CHEN = (1<<0)|(1<<1)|(1<<2)|(1<<3);

	PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->OUT[1]);
	PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[2]);
	PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[3]);
	PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);



	int sleep = 0;

	while(1);



	while(1){

		if(((GPIO->IN & (1<<17)) == 0)) {
			GPIO->OUTSET = (1 << 13)|(1<<14)|(1<<15);
			for(int i = 4; i<13; i++){
				GPIO->OUTCLR = (1<<i);
			}		

		}


		if(((GPIO->IN & (1<<26)) == 0)){
			GPIO->OUTCLR = (1 << 13)|(1<<14)|(1<<15);
			for(int i = 4; i<13; i++){
				GPIO->OUTSET = (1<<i);	
			}
		}	

		
	

	
		sleep = 10000;
		while(--sleep);
	}
	return 0;
}


