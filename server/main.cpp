// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
//#include <bcm2835.h>
//#include <stdio.h>
//#include <pin.h>

//// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
//#define PIN RPI_GPIO_P1_11
//int main(int argc, char **argv)
//{
//    // If you call this, it will not actually access the GPIO
//    // Use for testing
//    bcm2835_set_debug(1);

//    Pin * pin = new Pin(PIN);

//    if (!bcm2835_init())
//      return 1;
//    // Set the pin to be an output
//    pin->changeDir();
//    // Blink
//    while (1)
//    {
//        // Turn it on
//        pin->setValue(HIGH);

//        // wait a bit
//        bcm2835_delay(500);

//        // turn it off /////////
//        pin->setValue(LOW);

//        // wait a bit
//        bcm2835_delay(500);
//    }
//    bcm2835_close();
//    delete pin;
//    return 0;
//}


#include <bcm2835.h>
#include <stdio.h>
#include <pin.h>
#include <pwm.h>

// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024
int main(int argc, char **argv)
{
    bcm2835_set_debug(1);



    if (!bcm2835_init())
        return 1;

    Pin * pin = new Pin(PIN);

    PWM * pwm = new PWM( 1.2 , 58 );


    // Set the output pin to Alt Fun 5, to allow PWM channel 0 to be output there
    bcm2835_gpio_fsel(pin->getPinNr(), BCM2835_GPIO_FSEL_ALT5);

    // Vary the PWM m/s ratio between 1/RANGE and (RANGE-1)/RANGE
    // over the course of a a few seconds
    int direction = 1; // 1 is increase, -1 is decrese

    int data = pwm->getDutyPercentage();

    while (1)
    {
        if (data == 100)
            pwm->setDuty(0);
        else {
            int newPercent = pwm->getDutyPercentage() - 10;
            pwm->setDuty(newPercent);
        }
        bcm2835_delay(1);
    }


    bcm2835_close();
    return 0;
}
