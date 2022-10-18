#ifndef RAMPUP_ARDUINO_HPP
#define RAMPUP_ARDUINO_HPP

#include "EVT/io/I2C.hpp"
#include "EVT/io/UART.hpp"

class Arduino {
    /** A static variable for the Arduino's address. */
    static constexpr uint8_t ARDUINO_ADDRESS = 0x04;

    /** A static variable for the memory address of the Arduino's ID. */
    static constexpr uint8_t ID_REGISTER = 0x00;

    /** A static variable for the memory address of the Arduino's least significant byte of the temperature data. */
    static constexpr uint8_t LSTD_REGISTER = 0x01;

    /** A static variable for the memory address of the Arduino's most significant byte of the temperature data. */
    static constexpr uint8_t MSTD_REGISTER = 0x02;

    /** A static variable for the memory address of the Arduino's least significant byte of the voltage data. */
    static constexpr uint8_t LSVD_REGISTER = 0x03;

    /** A static variable for the memory address of the Arduino's most significant byte of the voltage data. */
    static constexpr uint8_t MSVD_REGISTER = 0x04;

    /** A reference to the I2C connection used by the Arduino. */
    EVT::core::IO::I2C& i2c;

    /** A reference to the UART connection used by the Arduino. */
    EVT::core::IO::UART& uart;

    /**
     * A shell function for reading a register on the Arduino over I2C
     * @param reg the register to read at.
     * @return the value at reg.
     */
    uint8_t readRegister(uint8_t reg);
public:
    /**
     * Setup an Arduino with a given I2C connection and UART connection.
     * @param i2C the I2C connection for the Arduino to communicate over
     * @param uart the UART connection for the Arduino to communicate serial data
     */
    Arduino(EVT::core::IO::I2C &i2C, EVT::core::IO::UART &uart);

    /**
     * Get ID retrieves the ID of the Arduino device.
     * @return the value for ID.
     */
    uint8_t getID();

    /**
     * Get the least significant byte of the temperature data (LSTD).
     * @return the value for the LSTD.
     */
    uint8_t getLSTD();

    /**
     * Get the most significant byte of the temperature data (MSTD).
     * @return the value for the MSTD.
     */
    uint8_t getMSTD();

    /**
     * Get the least significant byte of the voltage data (LSVD).
     * @return the value for the LSVD.
     */
    uint8_t getLSVD();

    /**
     * Get the most significant byte of the voltage data (MSVD).
     * @return the value for the MSVD.
     */
    uint8_t getMSVD();

    /**
     * Calculate the temperature of the Arduino by combining the LSTD and MSTD.
     * @return the temperature of the Arduino.
     */
    uint16_t getTemperature();

    /**
     * Calculate the temperature of the Arduino by combining the LSVD and MSVD.
     * @return the voltage of the Arduino.
     */
    uint16_t getVoltage();
};


#endif //RAMPUP_ARDUINO_HPP
