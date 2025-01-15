/**
 * Test to see if the numbers 1 through 10 are even or odd. 
 */
#include <stdio.h>

int main() {
  int aNumber; //Number to test for oddness
  for (aNumber = 1; aNumber <= 10; ++aNumber) {
    if((aNumber % 2) == 1) {
      printf("%d is odd \n", aNumber);
    } else {
      printf("%d is even\n", aNumber);
    }
  }
  return (0);
}