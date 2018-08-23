/*
 * usci.c
 *
 *  Created on: 19 срхїз 2016
 *      Author: etty
 */

#include "usci.h"
#include <avr/delay.h>
#include <avr/io.h>


/*
 * - Implements the following SPI interface functions
 *	- init
 *	- transmit
 *	- exchange
 *
 */

// Include files

/*
 * Initialise SPI port
 * 	- Master, 8 bits, mode 0:0, max speed, 3 wire
 * 	- Clock = 0: SMCLK /2 (works with no external clock input, DCO only)
 *	- Clock = 1: ACLK  /2 (fastest possible, from external clock input)
 */

// Master
void spi_masterInit(void)
{
	//PORTB &= ~((1<<PB5)|(1<<PB4)|(1<<PB3));

	//MCUCR &= ~(1<<PUD);
	DDRB |= (1<<DDB5)|(1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0);
	DDRB &= ~(1<<DDB4);

	SPSR &= ~(1<<SPI2X);


	//SPCR = ((1<<CPOL)|(1<<CPHA)|(1<<SPE)|(1<<MSTR)|(1<<SPR0));
	SPCR |= ((1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1));
	printf("SPCR = %d", SPCR);
	char temp = SPCR;
	ptinrHEXLE(temp);
	printf("\n SPCS = ");
	temp = SPSR;
	ptinrHEXLE(temp);


	PORTB |= (1<<PB2); // maybe SS#
	PORTB |= (1<<PB1);
	PORTB &= ~(1<<PB0);

}

void usci_transmit(unsigned char cData)
{
	SPDR = cData;
	while(!(SPSR & (1<<SPIF))); // waite for SPI interrupt flag on

	SPDR;
}

unsigned char usci_exchange( unsigned char data )
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF))); // waite for SPI interrupt flag on
	return SPDR;
}



//Slave
 void spi_slaveInit(void)
 {
	 SPI = (1<<MISO);
	 SPCR = (1<<SPE);
 }

 unsigned char spi_slaveReceive(void)
 {
	 while(!(SPSR & (1<<SPIF)));
	 return SPDR;
 }

