/**
 * See what happens when we exceed the maximum number.
 * (Contains an intentional mistake for illustrative purposes)
 * [turns out the mistake is only relevant in smaller systems]
*/
#include <stdio.h>
#include <stdint.h>

int main(){
  //Very small integer, set to the maximum
  uint8_t smallNumber = 255;

  printf("255+1 %u\n", smallNumber + 1);
  return(0);
}