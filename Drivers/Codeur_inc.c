#include "stm32f10x.h"
#include "Codeur_inc.h"
#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"


void Encoder_Init(TIM_TypeDef * Timer){
	MyTimer_Base_Init(Timer, 1400, 1);

  Timer->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;

	Timer->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0;
		 
	Timer->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);
	Timer->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
 
	Timer->CR1 |= TIM_CR1_CEN;
	
	MyGPIO_Init(GPIO_IC1_CodIncr, GPIOPin_IC1_CodIncr, In_Floatting);
	MyGPIO_Init(GPIO_IC2_CodIncr, GPIOPin_IC2_CodIncr, In_Floatting);
}

void Z_Pin_Interrupt_Init(void) {
  // Assuming Z is connected to pin PA0 (EXTI line 0)
	MyGPIO_Init(GPIO_Z, GPIOPin_Z, In_Analog);
	
	// Enable EXTI0 interrupt
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;  // Enable AFIO clock
	AFIO->EXTICR[0] &= ~AFIO_EXTICR1_EXTI0;  // Map EXTI0 to PA0

	EXTI->IMR |= EXTI_IMR_MR0;  // Unmask EXTI line 0
	EXTI->RTSR |= EXTI_RTSR_TR0;  // Trigger on rising edge

	// Enable the interrupt in the NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(TIM_TypeDef * Timer) {
	if (EXTI->PR & EXTI_PR_PR0) {  // Check if EXTI line 0 triggered
		Timer->CNT = 0;  // Reset the counter
		EXTI->PR |= EXTI_PR_PR0;  // Clear the pending bit
	}
}

uint32_t read_encoder_value(TIM_TypeDef * Timer){
	return Timer->CNT;
}