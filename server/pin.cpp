#include "pin.h"
#include <bcm2835.h>

Pin::Pin (int pin) {
    this->pin_nr = pin;
    this->direction = 0;
    bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    this->pull_up = 0;
}

Pin::Pin(int pin, int dir, int pull_up) {
    this->pin_nr = pin;
    this->direction = dir;
    if(dir == 1) {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_OUTP);
    }
    else {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    }
    this->pull_up = pull_up;
}

int Pin::getValue(void) {
    return bcm2835_gpio_lev(this->pin_nr);
}

void Pin::changeDir(void) {

    if(this->direction == 0) {
        /** input to output */
        this->direction = 1;
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_OUTP);
    }
    else {
        this->direction = 0;
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    }
}
