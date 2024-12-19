#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"
#include "USART.h"
#include "Communication.h"
#include "PlateauService.h"

int received_vitesse;
char received_sens;

int main(void) {
	initPlateau();
	Communication_Conf();

	while (1) {			
		received_vitesse= read_vitesse();
		received_sens = read_sens();
		controlVitesse(received_vitesse);
		controlSens(received_sens);
	}
}