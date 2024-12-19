#ifndef CONSTANTES_H
#define CONSTANTES_H

// Plateau 
#define TimerPWM_Plateau TIM2
#define GPIO_Sens_Plateau GPIOA
#define GPIO_Vitesse_Plateau GPIOA
#define GPIOPin_Sens_Plateau 2
#define GPIOPin_Vitesse_Plateau 1
#define Channel_Plateau 2

// Servo Moteur ( Voile )
#define GPIO_ServoMoteur GPIOA
#define GPIOPin_ServoMoteur 7
#define TimerServo_Moteur TIM3
#define Channel_ServoMoteur 2 

// Girouette
#define TimerComIncremental TIM1
#define GPIO_IC1_CodIncr GPIOA
#define GPIOPin_IC1_CodIncr 6
#define GPIO_IC2_CodIncr GPIOA
#define GPIOPin_IC2_CodIncr 9
#define GPIO_Z GPIOA
#define GPIOPin_Z 0

//Telecommande
#define GPIO_RX GPIOA
#define GPIOPin_RX 10
#define GPIO_TX GPIOA
#define GPIOPin_TX 9
#define TimerTelecommande TIM2



#endif
