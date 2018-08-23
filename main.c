/*
 * main.c
 *
 *  Created
 *      Author: etty
 */
#include "usci.h"
#include "stdio.h"
#include <avr/delay.h>
#include "main.h"
#include "can.h"
#include "uart.h"

//#include <avr/iom328p.h>




int main (void) {

stdout = &mystdout; 	// setup our stdio stream
USART_Init(MYUBRR);
spi_masterInit();

printf("\n"
"================================================s\n"
" BBBBB   GGGGG   RRRRR                             \n"
" BB   B GGG      RR   R     CCCC    A    N    N    \n"
" BBBBB  GG  GGG  RRRRR     CC      A A   N N  N    \n"
" BB   B GGG  GG  RR   R    CC     AAAAA  N  N N    \n"
" BBBBB   GGGGG   RR   R     CCCC A     A N    N    \n"
"================================================\n");
unsigned char buffer[100]; //set buffer
unsigned char byets=0;
int boolian;
int temp;
unsigned char seand = 0x0;

printf("set bit rate");
 int CAN_BITRATE = enter_char();
 printf("%d",CAN_BITRATE);
can_init(CAN_BITRATE);
boolian = YesNoQ( "Set Prime mode","Receive","Transmit");

if(boolian){
	printf("Receive");
while(1){ //

	   PORTB |= (1<<PB1);

		can_read( CANINTF, buffer, 1 );
		if(buffer[0]&0x03){
			//printf("recive");
		printf("recive \n");
		can_receive();

		printf("%c ",can.data.data_u8[0]);
		printf("%c ",can.data.data_u8[1]);
		printf("%c ",can.data.data_u8[2]);
		printf("%c ",can.data.data_u8[3]);
		printf("%c ",can.data.data_u8[4]);
		printf("%c ",can.data.data_u8[5]);
		printf("%c ",can.data.data_u8[6]);
		printf("%c \n ",can.data.data_u8[7]);








		/*
		switch(can.address)
		{
		case MC_CAN_BASE:		 //
			printf("Identification Information \n");
			printf("Serial Number %lu \n",can.data.data_u32[0]);
			printf("Tritium ID    %lu \n\n",can.data.data_u32[1]);
					break;
		case MC_CAN_BASE + MC_LIMITS:		 //
			printf("Status Information \n");
			printf("Receive error count  %d \n",can.data.data_u8[0]);
			printf("Transmit error count %d \n",can.data.data_u8[1]);
			printf("Active Motor         %d \n",can.data.data_u16[1]);
			printf("Error Flags          %d \n",can.data.data_u16[2]);
			printf("Limit Flags          %d \n\n",can.data.data_u16[3]);
			break;
		case MC_CAN_BASE + MC_BUS:		 //
			printf("Bus Measurement \n");
			double temp1;
			temp1 =can.data.data_u8[0];
			printf("Receive error count  %d%d%d%d \n",can.data.data_u8[0],can.data.data_u8[1],can.data.data_u8[2],can.data.data_u8[3]);
			printf("Transmit error count %d%d%d%d \n\n",can.data.data_u8[3],can.data.data_u8[5],can.data.data_u8[6],can.data.data_u8[7]);
					break;
		case MC_CAN_BASE + MC_VELOCITY:		 //
					break;
		case MC_CAN_BASE + MC_PHASE:		 //
					break;
		case MC_CAN_BASE + MC_V_VECTOR:		 //
					break;
		case MC_CAN_BASE + MC_I_VECTOR:		 //
					break;
		case MC_CAN_BASE + MC_BEMF_VECTOR:		 //
					break;
		case MC_CAN_BASE + MC_RAIL1:		 //
					break;
		case MC_CAN_BASE + MC_RAIL2:		 //
					break;
		case MC_CAN_BASE + MC_FAN:		 //
					break;
		case MC_CAN_BASE + MC_TEMP1:		 //
					break;
		case MC_CAN_BASE + MC_TEMP2:		 //
					break;
		case MC_CAN_BASE + MC_TEMP3:		 //
					break;
		case MC_CAN_BASE + MC_CUMULATIVE:		 //
					break;

		}//switch
		*/
	}//if
	}//while
}//if
else {
	char j = 0;
	printf("transmiter");
	while(1){
		_delay_ms(50);


					//byets = loadString(buffer,"enter data to send\n");  //write payload to TX_FIFO


					buffer[0] =1+j;
					buffer[1] =2+j;
					buffer[2] =3+j;
					buffer[3] =4+j;
					buffer[4] =5+j;
					buffer[5] =6+j;
					buffer[6] =7+j;
					buffer[7] =8+j;

					j++;
					if(j == 250)
						j=0;
					can_push_ptr->address = 420;
					can_push_ptr->status = 8;






					can_push_ptr->data.data_u8[0] = buffer[0];

					can_push_ptr->data.data_u8[1] = buffer[1];

					can_push_ptr->data.data_u8[2] = buffer[2];

					can_push_ptr->data.data_u8[3] = buffer[3];

					can_push_ptr->data.data_u8[4] = buffer[4];

					can_push_ptr->data.data_u8[5] = buffer[5];

					can_push_ptr->data.data_u8[6] = buffer[6];

					can_push_ptr->data.data_u8[7] = buffer[7];

					can_push();


					can_transmit();


					buffer[0] = 0;
					while((!(buffer[0]&(7<<2)))&&!(byets==50))  // while TX_DS != 1
					{
						can_read( CANINTF, buffer, 1 );
						byets++;
						_delay_us(10);
					}
					if(byets==50) printf("massige error\n");
					else printf("massige ok\n");


			}//while
}

return 1;

}//main











