/**
 * Defining a serial I/O register that contains a 2-bit value for the parity
 * (will have an expression written to extract the parity checking number in the range 0-3)
 * (The parity is stored in bits 2 and 3 as a 2-bit unsigned binary number)
*/
#include <stdio.h>
#include <stdint.h>

const uint8_t SERIAL_IO_ON = 0b10;
const uint8_t SERIAL_IO_OFF = 0b00;

int main() {
  printf("SERIAL I/O status %x\n", SERIAL_IO_ON);
  printf("SERIAL I/O status %x\n", SERIAL_IO_OFF);
  return(0);
}