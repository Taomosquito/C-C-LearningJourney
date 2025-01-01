/** 
 * Program to demonstrate the use of bit operations
*/

#include <stdio.h>
#include <stdint.h>

// < Master fail -- shows if any other error is present.
const uint8_t MASTER_FAIL         = (1 << 7);
// < Indicates that inconsistent data was received.
const uint8_t DATA_FAIL           = (1 << 6);
// < Oil container is low.
const uint8_t OIL_LOW             = (1 << 5);
// < Oil pressure is low.
const uint8_t OIL_PRESSURE        = (1 << 4);
// < Main power supply failed.
const uint8_t POWER_FAILURE       = (1 << 3);
// < We told the position to go x and it didn't.
const uint8_t POSITION_FAULT      = (1 << 2);
// < Air compressor stopped.
const uint8_t AIR_PRESSURE        = (1 << 1);
// < Air filter has reached end of life.
const uint8_t CLEAN_FILTER        = (1 << 0);
/*!
 * Prints the state of the bits
 * (Substitutes for real LCD panel) 
 * 
 * \param ledRegister Register containing the LED bits 
*/
static void printLED(const uint8_t ledRegister){
  printf("Leds: ");
  if((MASTER_FAIL & ledRegister) != 0)
    printf("MASTER_FAIL ");
  if((DATA_FAIL & ledRegister) != 0)
    printf("DATA_FAIL ");
  if((OIL_LOW & ledRegister) != 0)
    printf("OIL_LOW ");
  if((OIL_PRESSURE & ledRegister) != 0)
    printf("OIL_PRESSURE ");
  if((POWER_FAILURE & ledRegister) != 0)
    printf("POWER_FAILURE ");
  if((POSITION_FAULT & ledRegister) != 0)
    printf("POSITION_FAULT ");
  if((AIR_PRESSURE & ledRegister) != 0)
    printf("AIR_PRESSURE ");
  if((CLEAN_FILTER & ledRegister) != 0)
    printf("CLEAN_FILTER ");
  printf("\n");
}
int main(){
  uint8_t ledRegister = 0x00;         // Start with all off.
  
  printLED(ledRegister);

  //Power went out.
  ledRegister |= POWER_FAILURE | MASTER_FAIL;
  printLED(ledRegister);

  // Now the air went out.
  ledRegister |= AIR_PRESSURE;
  printLED(ledRegister);

  // Power back, air out, so master is on.
  ledRegister &= ~POWER_FAILURE;
  printLED(ledRegister);
  return (0);
}