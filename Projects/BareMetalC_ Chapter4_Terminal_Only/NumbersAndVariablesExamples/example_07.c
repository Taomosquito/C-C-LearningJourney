/**
 * See what happens when we exceed the maximum number.
*/
#include <stdio.h>
#include <stdint.h>

int main(){
  uint8_t smallNumber;
  uint8_t result;

  smallNumber = 255;
  result = smallNumber + 1;
  printf("255+1 is %d\n", result);
  return(0);
}