#ifndef PWM_H
#define PWM_H


class PWM
{
    private:
        int freq;
        int duty;

    public:
        PWM(int freq, int duty);
        int getFreq();
        void setFreq(int freq);
        int getDuty();
        void setDuty(int duty);
        int getDutyPercentage();
};

#endif // PWM_H
