#include "LED.h"   // Include the header for LED functionality
#include "gpio.h"  // Include the header for GPIO (General Purpose Input/Output) functionality

// Function to initialize the LED pins
void LEDS_init(void)
{
	// Set the direction of each LED pin to output
	GPIO_setupPinDirection(LED_PORT_ID, RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, BLUE_PIN_ID, PIN_OUTPUT);

	// Initialize all LEDs to OFF state based on the defined logic
#ifdef LOGIC_POSITIVE
	{
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_LOW);   // Turn off red LED
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_LOW); // Turn off green LED
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_LOW);  // Turn off blue LED
	}
#else
	{
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_HIGH);  // Turn off red LED (LOGIC NEGATIVE)
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_HIGH); // Turn off green LED (LOGIC NEGATIVE)
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_HIGH);  // Turn off blue LED (LOGIC NEGATIVE)
	}
#endif
}

// Function to turn on a specific LED
void LED_on(LED_ID id)
{
	switch (id) {
	case LED_RED:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_HIGH); // Turn on red LED
#else
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_LOW);  // Turn on red LED (LOGIC NEGATIVE)
#endif
		break;
	case LED_GREEN:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_HIGH); // Turn on green LED
#else
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_LOW);  // Turn on green LED (LOGIC NEGATIVE)
#endif
		break;
	case LED_BLUE:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_HIGH); // Turn on blue LED
#else
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_LOW);  // Turn on blue LED (LOGIC NEGATIVE)
#endif
		break;
	default:
		// Handle invalid LED_ID if necessary
		break;
	}
}

// Function to turn off a specific LED
void LED_off(LED_ID id)
{
	switch (id) {
	case LED_RED:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_LOW);  // Turn off red LED
#else
		GPIO_writePin(LED_PORT_ID, RED_PIN_ID, LOGIC_HIGH); // Turn off red LED (LOGIC NEGATIVE)
#endif
		break;
	case LED_GREEN:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_LOW);  // Turn off green LED
#else
		GPIO_writePin(LED_PORT_ID, GREEN_PIN_ID, LOGIC_HIGH); // Turn off green LED (LOGIC NEGATIVE)
#endif
		break;
	case LED_BLUE:
#ifdef LOGIC_POSITIVE
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_LOW);  // Turn off blue LED
#else
		GPIO_writePin(LED_PORT_ID, BLUE_PIN_ID, LOGIC_HIGH); // Turn off blue LED (LOGIC NEGATIVE)
#endif
		break;
	default:
		// Handle invalid LED_ID if necessary
		break;
	}
}
