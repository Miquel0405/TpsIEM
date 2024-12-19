#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"
#include <stdio.h>


void initServoMoteur(){
	MyGPIO_Init(GPIO_ServoMoteur,GPIOPin_ServoMoteur, AltOut_Ppull);
	//timer PWM pposition Servomotor	
	MyTimer_Base_Init(TimerServo_Moteur,72,20000);
	int cycle=50;
	
	//INIT
	MyTimer_Base_Start(TimerServo_Moteur);
	MyTimer_PWM(TimerServo_Moteur,Channel_ServoMoteur);
	MyTimer_SetDutyCycle(TimerServo_Moteur,Channel_ServoMoteur, cycle);

}


void setPosServoMoteur(int dutycycle){ //nombre entre 1-100
	//1ms-2ms de 20ms -> entre 5 et 10 %
	double changement = dutycycle * 0.05;
	changement +=5;
	MyTimer_SetDutyCycle(TimerServo_Moteur,Channel_ServoMoteur, changement);
}