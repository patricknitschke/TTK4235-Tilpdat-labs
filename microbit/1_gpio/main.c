#include <stdint.h>
#include "uart.h" 
#include <stdio.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)


ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
		}
	return count;
}

ssize_t _read(int fd, void *buf, size_t cont){
	char *str = (char *)(buf);
	char letter;
	do {
		letter = uart_read();
	} while(letter == '\0');
	*str = letter;
	return 1;
}


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

	int sleep = 0;

	uart_init();

	//uart_send('A');	
	//uart_send('B');	


	while(1){
		char read = uart_read();

		if(((GPIO->IN & (1<<17)) == 0) | (read == 'a')) {
			GPIO->OUTSET = (1 << 13)|(1<<14)|(1<<15);
			for(int i = 4; i<13; i++){
				GPIO->OUTCLR = (1<<i);
			}
			uart_send('A');		

		}


		if(((GPIO->IN & (1<<26)) == 0)|(read == 'b')){
			GPIO->OUTCLR = (1 << 13)|(1<<14)|(1<<15);
			for(int i = 4; i<13; i++){
				GPIO->OUTSET = (1<<i);	
			}
			uart_send('B');
			iprintf("Norway has %d coutries. \n\r", 18);
			iprintf("%d" , 5*4);
		}	

		
	

	
		sleep = 10000;
		while(--sleep);
	}
	return 0;
}


