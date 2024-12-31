/**
 * Below is a solution to the problem listed as follows:
 ***  "Write a program to find out what the int16-t value of 32767 + 1 is"
*/
#include <stdio.h>
#include <stdint.h>

int main() {
  int16_t MAXIMUM_VALUE_FOR_RANGE_SPEC = 32767;
  // Had to fight with autopromotion and this is my result!
  uint16_t result = MAXIMUM_VALUE_FOR_RANGE_SPEC + 1;

  printf("After casting result to int16_t: %d\n", (int16_t)result);
  return(0);
}