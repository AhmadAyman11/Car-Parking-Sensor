#ifndef BUZZER_H_  // Include guard to prevent multiple inclusions
#define BUZZER_H_

#include "std_types.h"  // Include standard types header for type definitions

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

// Define the port and pin ID for the buzzer
#define BUZZER_PORT_ID      PORTC_ID  // Port where the buzzer is connected
#define BUZZER_PIN_ID       PIN5_ID    // Pin ID for the buzzer

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

// Function to initialize the buzzer
void Buzzer_init(void);

// Function to turn the buzzer on
void Buzzer_on(void);

// Function to turn the buzzer off
void Buzzer_off(void);

#endif /* BUZZER_H_ */  // End of include guard
