#ifndef SPI_H
#define SPI_H
#include"serial.h"

class SPI: public Serial {

    public:
        SPI(uint8_t bitOrder, uint8_t SPIMode, uint16_t clockDivider, uint8_t cs0);
        uint8_t transfer(uint8_t data);

};

#endif // SPI_H
