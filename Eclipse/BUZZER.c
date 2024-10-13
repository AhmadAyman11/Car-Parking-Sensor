#include "BUZZER.h"  // Include the header for buzzer functionality
#include "gpio.h"    // Include the GPIO (General Purpose Input/Output) header

// Function to initialize the buzzer
void Buzzer_init(void)
{
	// Set the direction of the buzzer pin to output
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);

	// Initialize the buzzer pin to low (buzzer off)
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

// Function to turn the buzzer on
void Buzzer_on(void)
{
	// Set the buzzer pin to high to activate the buzzer
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

// Function to turn the buzzer off
void Buzzer_off(void)
{
	// Set the buzzer pin to low to deactivate the buzzer
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
