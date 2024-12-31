/**
 * Simple use of uint8_t
*/
#include <stdio.h>
#include <stdint.h>

int main(){
  uint8_t smallNumber = 0x12; // A small number

  printf("0x12 is %u decimal\n", smallNumber);
  printf("0x12 is %o octal\n", smallNumber);
  printf("0x12 is %x hex\n", smallNumber);
  return(0);
}