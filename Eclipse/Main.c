#include <avr/io.h>
#include "common_macros.h"
#include <util/delay.h>
#include "gpio.h"
#include "BUZZER.h"
#include "lcd.h"
#include "LED.h"
#include "std_types.h"
#include "icu.h"
#include "ultrasonic.h"



int main(void)
{
	SET_BIT(SREG,7);
	LCD_init();               // Initialize the LCD
	Buzzer_init();            // Initialize the buzzer
	LEDS_init();              // Initialize the LEDs
	Ultrasonic_init();        // Initialize the Ultrasonic

	uint16 Distance = 0; // Variable to store distance read by the ultrasonic sensor

	LCD_displayString("Distance=   CM");

	while(1)
	{
		/* Read the distance from the ultrasonic sensor */
		Distance = Ultrasonic_readDistance();


		if (Distance > 100)
		{
			/* If the distance is more than 100 cm, display it directly */
			LCD_moveCursor(0,9);
			LCD_intgerToString(Distance);
		}
		else
		{
			LCD_moveCursor(0,9);
			LCD_intgerToString(Distance);
			// Clear the next character on the LCD if present
			LCD_displayCharacter(' ');
		}


		/* Check for dangerous proximity (distance <= 5 cm) */
		if(Distance <= 5)
		{
			Buzzer_on();
			LCD_moveCursor(1,6);
			LCD_displayString("STOP");
			/* Keep blinking the LEDs and refreshing the distance until the obstacle is removed */
			while (Distance <= 5)
			{
				Distance = Ultrasonic_readDistance();
				LCD_moveCursor(0,9);
				LCD_intgerToString(Distance);
				LED_on(0);
				LED_on(1);
				LED_on(2);
				_delay_ms(200);
				LED_off(0);
				LED_off(1);
				LED_off(2);
				_delay_ms(200);
			}
			/* Once the distance is safe, turn off the buzzer and LEDs */
			Buzzer_off();
			LED_off(0);
			LED_off(1);
			LED_off(2);
			/* Clear the STOP message on the LCD */
			LCD_moveCursor(1,0);
			LCD_displayString("                ");
		}
		/* If the distance is between 6 and 10 cm */
		else if(Distance <= 10)
		{
			LED_on(0);
			LED_on(1);
			LED_on(2);
		}
		/* If the distance is between 11 and 15 cm */
		else if(Distance <= 15)
		{
			LED_on(0);
			LED_on(1);
			LED_off(2);
		}
		/* If the distance is between 16 and 20 cm */
		else if(Distance <= 20)
		{
			LED_on(0);
			LED_off(1);
			LED_off(2);
		}
		/* If the distance is more than 20 cm */
		else
		{
			LED_off(0);
			LED_off(1);
			LED_off(2);
		}

		/* Add a small delay for stability */
		_delay_ms(100);

	}


}
