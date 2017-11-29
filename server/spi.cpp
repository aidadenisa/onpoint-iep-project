#include "spi.h"

SPI::SPI(uint8_t bitOrder, uint8_t SPIMode, uint16_t clockDivider, uint8_t cs0) {
    bcm2835_spi_setBitOrder(bitOrder);      // The default
        bcm2835_spi_setDataMode(SPIMode);                   // The default
        bcm2835_spi_setClockDivider(clockDivider); // The default
        bcm2835_spi_chipSelect(cs0);                      // The default
        bcm2835_spi_setChipSelectPolarity(cs0, LOW);
}

uint8_t SPI::transfer(uint8_t data) {
    return bcm2835_spi_transfer(send_data);
}
