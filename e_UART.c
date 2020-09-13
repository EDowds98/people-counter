/*  
 *	This basic UART library was cobbled together from several other libraries,
 *	particularly from maxembedded.com and the Make: AVR book
 *
 *	this code is for 9600 baud with 8 data bits and one stop bit
 *
 *	Written by Eric Dowds ed67@hw.ac.uk 13/09/2020
 */  
#include <avr/io.h>
#include "e_UART.h"

// function to initialize UART
void e_UART_init (void) {
	UBRR0H = 12 >> 8;                      // shift the register right by 8 bits
   	UBRR0L = 12;                           // set baud rate
	UCSR0A |= (1 << U2X0);
    	UCSR0B |= (1 << TXEN0)|(1 << RXEN0);                // enable receiver and transmitter
    	UCSR0C |= (1 << UCSZ00)|(1 << UCSZ01);   // 8bit data format
	
}

void e_UART_transmit(unsigned char data) {
	while (!(UCSR0A & (1 << UDRE0)));                // wait while register is free
    	UDR0 = data;                                   // load data in the register
}

// function to receive data
unsigned char e_UART_recieve(void) {
    	while(~(UCSR0A) & (1 << RXC0));                   // wait while data is being received
    	return UDR0;                                   // return 8-bit data
}

