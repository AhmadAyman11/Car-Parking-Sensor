#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Define the port and pin for the Echo signal.
 * The Echo pin receives the reflected ultrasonic pulse.
 */
#define UltraSonic_ECHO_PORT_ID     PORTD_ID
#define UltraSonic_ECHO_PIN_ID      PIN6_ID

/*
 * Define the port and pin for the Trigger signal.
 * The Trigger pin sends out an ultrasonic pulse to be reflected back by an object.
 */
#define UltraSonic_TRIGGER_PORT_ID  PORTD_ID
#define UltraSonic_TRIGGER_PIN_ID   PIN7_ID

/*
 * Define the delay value used to create the trigger pulse.
 * The ultrasonic sensor requires a 10 µs trigger pulse, and this constant
 * can be adjusted to achieve the correct pulse timing.
 */
#define TRIGGER_DELAY_VALUE     15

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize the ultrasonic sensor by setting up the required hardware pins
 * and configuring any necessary timers or interrupts for measuring the echo pulse.
 */
void Ultrasonic_init(void);

/*
 * Description:
 * Send a trigger pulse to the ultrasonic sensor.
 * This function will set the trigger pin high for a specific time, then set it low.
 */
void Ultrasonic_Trigger(void);

/*
 * Description:
 * Read the distance measured by the ultrasonic sensor.
 * The distance is calculated by measuring the time between sending the trigger pulse
 * and receiving the echo pulse. The result is returned in centimeters.
 *
 * Returns:
 * The distance to the object in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 * Callback function for processing the edges of the echo signal.
 * This function is typically called inside an interrupt service routine (ISR)
 * when a change is detected on the Echo pin (rising or falling edge).
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_SENSOR_H_ */
