#ifndef PIN_H
#define PIN_H

#define OFF_VALUE               0u
#define ON_VALUE                1u

class Pin
{
public:
    Pin(int pin);
    Pin(int pin, int dir, int pull_up);
    void set(int Option);
    int getValue(void);
    void setValue( unsigned char value );
    void changeDir(void);

private:
    int pin_nr;
    int pull_up; // 0- no, 1- yes
    int direction;  // 0 - input, 1 - output

};

#endif // PIN_H
