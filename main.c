
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "avr/interrupt.h"
#include "AVR_Ports.h"
#include "AVR_LCD_Declarations.h"

int main(void)
{
	
	uint16_t period; //time delay between every step angle
	DDRA = 0x0F;		//Make PORTA lower pins as output
	period = 1000;		//Set period in between two steps [in ms]

		//Rotate Stepper Motor Anticlockwise with [Half step sequence]
		//step angle of the motor in proteus = 30, then stepper motor will rotate with 15 step angle
		for (int x=0; x<3; x++)
		{
			//rotate with step angle of 15 [Half step sequence]
			//then for full cycle we need 360/15 = 24 angle steps
			//one for loop gives us 8 steps [8 driver instructions], [7 steps for the first for-loop only, 8 for the rest]
			//then for x[0-3] will give us a full cycle
			
			PORTA = 0x09; //1st step [put the motor at 0 only in the first for-loop], counts as a step in the rest for-loop(s)
			_delay_ms(period);
			
			PORTA = 0x08; //2nd step
			_delay_ms(period);
			PORTA = 0x0C; //3rd step
			_delay_ms(period);
			PORTA = 0x04; //4th step
			_delay_ms(period);
			PORTA = 0x06; //5th step
			_delay_ms(period);
			PORTA = 0x02; //6th step
			_delay_ms(period);
			PORTA = 0x03; //7th step
			_delay_ms(period);
			PORTA = 0x01; //8th step
			_delay_ms(period);
		}
		PORTA = 0x09; //last step [to reach 360 again], as only 345 are achieved above
		_delay_ms(period);
			
		_delay_ms(3000); //3 seconds delay between Anticlockwise and Clockwise
	
		//Rotate Stepper Motor Clockwise with [Full step sequence]
		//step angle of the motor in proteus = 30, then stepper motor will rotate with 30 step angle
		for (int x=0; x<3; x++)
		{
			//rotate with step angle of 30 [Full step sequence]
			//then for full cycle we need 360/30 = 12 angle steps
			//one for loop gives us 4 steps [4 driver instructions], [3 steps for the first for-loop only, 4 for the rest]
			//then for x[0-3] will give us a full cycle
			
			PORTA = 0x09; //1st step [put the motor at 0 only in the first for-loop], counts as a step in the rest for-loop(s)
			_delay_ms(period);
			
			//PORTA = 0x01; //2nd step
			//_delay_ms(period);
			PORTA = 0x03; //3rd step
			_delay_ms(period);
			//PORTA = 0x02; //4th step
			//_delay_ms(period);
			PORTA = 0x06; //5th step
			_delay_ms(period);
			//PORTA = 0x04; //6th step
			//_delay_ms(period);
			PORTA = 0x0C; //7th step
			_delay_ms(period);
			//PORTA = 0x08; //8th step
			//_delay_ms(period);
		}
		PORTA = 0x09; //last step [to reach 360 again], as only 310 are achieved above
		_delay_ms(period);
}
