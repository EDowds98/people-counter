#ifndef E_UART_H
#define E_UART_H

void e_UART_init(void);
void e_UART_transmit(unsigned char data);
unsigned char e_UART_receive(void); 

#endif
