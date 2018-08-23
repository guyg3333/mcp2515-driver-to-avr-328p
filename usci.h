/*
 * usci.h
 *
 *  Created on: 19 срхїз 2016
 *      Author: etty
 */

#ifndef USCI_H_
#define USCI_H_


#include <util/delay.h>


void spi_masterInit(void);
void usci_transmit(unsigned char cData);
unsigned char usci_exchange( unsigned char data );


//atmega register set
#define   SPI     (DDRB)
#define   MOSI    (DDB3)
#define   MISO    (DDB4)
#define   SCK     (DDB5)


#define   CE      (PB1)
#define   CSN     (PB2)


#endif /* USCI_H_ */
