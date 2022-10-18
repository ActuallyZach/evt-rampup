#include "Arduino.hpp"

namespace IO = EVT::core::IO;

Arduino::Arduino(IO::I2C &i2C, IO::UART &uart) : i2c(i2C), uart(uart) { }

uint8_t Arduino::readRegister(uint8_t reg) {
    return i2c.readReg(ARDUINO_ADDRESS, reg);
}

uint8_t Arduino::getID() {
    return readRegister(ID_REGISTER);
}


uint8_t Arduino::getLSTD() {
    return readRegister(LSTD_REGISTER);
}

uint8_t Arduino::getMSTD() {
    return readRegister(MSTD_REGISTER);
}

uint8_t Arduino::getLSVD() {
    return readRegister(LSVD_REGISTER);
}

uint8_t Arduino::getMSVD() {
    return readRegister(MSVD_REGISTER);
}

uint16_t Arduino::getTemperature() {
    uint16_t temperature = getMSTD();
    temperature <<= 8;
    temperature |= getLSTD();
    return temperature;
}

uint16_t Arduino::getVoltage() {
    uint16_t voltage = getMSVD();
    voltage <<= 8;
    voltage |= getLSVD();
    return voltage;
}


