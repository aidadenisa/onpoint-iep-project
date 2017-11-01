#include "pwm.h"
#include "bcm2835.h"

#define PWM_CHANNEL 0

PWM::PWM(int freq, int range)
{
    this->freq = freq;
    this->duty = duty * this->freq / 100;

    // Clock divider is set to 16.
    // With a divider of 16 and a RANGE of 1024, in MARKSPACE mode,
    // the pulse repetition frequency will be
    // 1.2MHz/1024 = 1171.875Hz, suitable for driving a DC motor with PWM
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, freq);
    bcm2835_pwm_set_data(PWM_CHANNEL, this->duty);
}

int PWM::getFreq() {
    return this->freq;
}

void PWM::setFreq(int freq) {
    this->freq = freq;
    bcm2835_pwm_set_range(PWM_CHANNEL, freq);
}

int PWM::getDuty() {
    return this->duty;
}

void PWM::setDuty(int duty) {
    this->duty = duty * this->freq / 100;
    bcm2835_pwm_set_data(PWM_CHANNEL, this->duty);

}

int PWM::getDutyPercentage() {
    return this->duty * 100 / this->freq;
}
