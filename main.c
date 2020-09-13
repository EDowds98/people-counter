#include <avr/io.h>
#include "e_UART.h"

int main(void) {
	e_UART_init();
	char name[] = "Eric\t";
	
	while(1) {
		int i = 0;
		while(name[i]) {
			e_UART_transmit(name[i]);
			i++;
		}
	}
	
	return 0;
}
