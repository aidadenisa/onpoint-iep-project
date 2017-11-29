#ifndef SERIAL_H
#define SERIAL_H
#include<stdin.h>
class Serial
{
   public:

      virtual uint8_t transfer(uint8_t data) =  0;

};
#endif // SERIAL_H

