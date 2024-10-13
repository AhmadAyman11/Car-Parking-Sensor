#include "ultrasonic.h"
#include "GPIO.h"
#include "ICU.h"
#include "avr/delay.h"

/* Global variable to store the pulse duration (high time of echo signal) */
static volatile uint16 g_highTime = 0;

/* Variable to store the calculated distance */
uint16 distance = 0;

/* Counter to keep track of rising and falling edges for echo signal */
static uint8 g_edgeCount = 0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * This function initializes the ultrasonic sensor by setting the trigger pin as output
 * and configuring the ICU (Input Capture Unit) to detect the echo signal on the rising edge.
 * It also sets up the callback function for edge processing (ISR).
 */
void Ultrasonic_init(void)
{
    /* Set the trigger pin as output */
    GPIO_setupPinDirection(UltraSonic_TRIGGER_PORT_ID, UltraSonic_TRIGGER_PIN_ID, PIN_OUTPUT);

    /* Configure ICU to use a prescaler of F_CPU/8 and detect the rising edge */
    ICU_ConfigType ICU_Config = {F_CPU_8, RAISING};
    ICU_init(&ICU_Config);

    /* Set the callback function to handle edge detection */
    ICU_setCallBack(Ultrasonic_edgeProcessing);
}

/*
 * Description:
 * Sends a trigger pulse to the ultrasonic sensor.
 * The pulse is high for a short duration (defined by TRIGGER_DELAY_VALUE)
 * and then pulled low, which triggers the ultrasonic sensor to send out a sound wave.
 */
void Ultrasonic_Trigger(void)
{
    /* Set trigger pin high */
    GPIO_writePin(UltraSonic_TRIGGER_PORT_ID, UltraSonic_TRIGGER_PIN_ID, LOGIC_HIGH);

    /* Wait for the required delay (at least 10µs) */
    _delay_us(TRIGGER_DELAY_VALUE);

    /* Set trigger pin low */
    GPIO_writePin(UltraSonic_TRIGGER_PORT_ID, UltraSonic_TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Description:
 * Triggers the ultrasonic sensor and calculates the distance based on the echo pulse width.
 * The formula used: distance = (high time of echo signal) / 117.6, which converts the time
 * to centimeters assuming the speed of sound in air (343 m/s).
 *
 * Returns:
 * The distance to the detected object in centimeters.
 */
uint16 Ultrasonic_readDistance(void)
{
    /* Send the trigger pulse */
    Ultrasonic_Trigger();

    /* Calculate distance in cm: high time / 117.6 (based on the speed of sound) */
    distance = g_highTime / 117.6;

    return distance;
}

/*
 * Description:
 * This function handles the processing of echo signal edges (rising and falling).
 * On the first rising edge, it clears the ICU timer and switches to detect the falling edge.
 * On the falling edge, it records the pulse duration (high time), switches back to rising edge,
 * and resets the edge count for the next trigger.
 */
void Ultrasonic_edgeProcessing(void)
{
    if (g_edgeCount == 0)
    {
        /* First edge: rising edge detected, start measuring the high time */
        ICU_clearTimerValue();  /* Clear the timer to start fresh */
        ICU_setEdgeDetectionType(FALLING);  /* Switch to detect falling edge */
        g_edgeCount = 1;  /* Increment edge count */
    }
    else if (g_edgeCount == 1)
    {
        /* Second edge: falling edge detected, capture the high time */
        g_highTime = ICU_getInputCaptureValue();  /* Store the captured time */
        ICU_setEdgeDetectionType(RAISING);  /* Switch back to rising edge */
        g_edgeCount = 0;  /* Reset edge count for the next cycle */
    }
}
