/**
 * This is a basic sample of using the UART module. The program provides a
 * basic echo functionality where the uart will write back whatever the user
 * enters.
 */
#include <EVT/utils/time.hpp>
#include <EVT/io/manager.hpp>
#include "Arduino/Arduino.hpp"

namespace IO = EVT::core::IO;
namespace time = EVT::core::time;

int main() {
    // Initialize system
    IO::init();

    // Setup UART
    IO::UART& uart = IO::getUART<IO::Pin::UART_TX, IO::Pin::UART_RX>(9600);

    // Setup i2c Communication
    IO::I2C& i2c = IO::getI2C<IO::Pin::PB_8, IO::Pin::PB_9>();

    Arduino temperatureController = Arduino(i2c, uart);

    while (1) {
        uart.printf("\n\rData Logged from Arduino:\n\r");
        uart.printf("Temperature: 0x%X\n\r", temperatureController.getTemperature());
        uart.printf("Voltage: 0x%X\n\r", temperatureController.getVoltage());

        uart.printf("ID: 0x%X\n\r", temperatureController.getID());
        uart.printf("LSTD: 0x%X\n\r", temperatureController.getLSTD());
        uart.printf("MSTD: 0x%X\n\r", temperatureController.getMSTD());
        uart.printf("LSVD: 0x%X\n\r", temperatureController.getLSVD());
        uart.printf("MSVD: 0x%X\n\r", temperatureController.getMSVD());

        time::wait(1000);
    }
}
