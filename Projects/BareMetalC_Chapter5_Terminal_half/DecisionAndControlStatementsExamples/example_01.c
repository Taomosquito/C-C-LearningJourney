/**
 * Test to see if the numbers 1 through 10 are even
 * or odd.
 */
#include <stdio.h>
int main(){
  int aNumber; // Number to test for oddness
  aNumber = 1;
  while(aNumber <= 10){
    if ((aNumber % 2) == 1){
      printf("%d is odd\n", aNumber);
    } else {
      printf("%d is even\n", aNumber);
    }
    ++aNumber;
  }
  return (0);
}