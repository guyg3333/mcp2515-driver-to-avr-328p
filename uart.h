/*
 * uart.h
 *
 *  Created on: 24 срхїз 2016
 *      Author: etty
 */

#ifndef UART_H_
#define UART_H_

#include "main.h"

#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
unsigned char usart_kbhit(void);
void usart_pstr(unsigned char *s);
int usart_putchar_printf(unsigned char var, FILE *stream);
int loadString(unsigned char* buffer,char* MASSEGE);
int YesNoQ( char* MASSEGE,char* yes, char*no);
void USART_Flush( void );
int enter_char();
static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, _FDEV_SETUP_WRITE);
static FILE uart_input = FDEV_SETUP_STREAM(NULL, USART_Receive, _FDEV_SETUP_READ);
void ptinrHEXLE( char hex);
void ptinrHEXBE( char hex);






#endif /* UART_H_ */
