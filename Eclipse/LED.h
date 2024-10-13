#ifndef LED_DRIVER_H  // Include guard to prevent multiple inclusions
#define LED_DRIVER_H

#include "std_types.h"  // Include standard types header for type definitions

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

// Define the port and pin IDs for the LEDs
#define LED_PORT_ID      PORTC_ID    // Port where LEDs are connected
#define RED_PIN_ID       PIN0_ID      // Pin ID for the red LED
#define GREEN_PIN_ID     PIN1_ID      // Pin ID for the green LED
#define BLUE_PIN_ID      PIN2_ID      // Pin ID for the blue LED
#define LOGIC_POSITIVE   // Define logic for LED operation (positive logic)

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

// Enumeration for LED IDs
typedef enum
{
	LED_RED,     // Identifier for the red LED
	LED_GREEN,   // Identifier for the green LED
	LED_BLUE,    // Identifier for the blue LED
	LED_COUNT    // Total number of LEDs (can be used for array sizes)
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

// Function to initialize the LED driver
void LEDS_init(void);

// Function to turn on a specified LED
void LED_on(LED_ID id);

// Function to turn off a specified LED
void LED_off(LED_ID id);

#endif // LED_DRIVER_H  // End of include guard
