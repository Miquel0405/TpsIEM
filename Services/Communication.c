#include "Communication.h"
#include "USART.h"
#include "GPIO.h"
#include "Timer.h"
#include <stdlib.h>
#include <stdio.h>


int recevoir_info_plateau(){
	received_data = USART_ReceiveChar(USART1);
	if (abs(received_data <= 100)) {
			return received_data;
  }
	return 0;
}

void send_angle(){
	USART_SendChar(USART1, angle);
}


void Communication_Conf(){
	MyGPIO_Init(GPIOA, 10, In_Floatting);
	MyGPIO_Init(GPIOA, 9, Out_Ppull);
	USART_Init(USART1, 9600);
	USART_EnableInterrupt(USART1, recevoir_info_plateau);
	
	MyTimer_Base_Init(TIM3, 7200, 30000);
	MyTimer_ActiveIT(TIM3, 3, send_angle);
}

