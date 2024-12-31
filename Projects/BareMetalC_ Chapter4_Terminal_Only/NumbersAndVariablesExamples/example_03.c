/**
 * Show different number types.
*/
#include <stdio.h>

int main(){
  short int aShortInt; //Short integer
  int aInteger; //Default integer
  long int aLongInt; //Long integer
  long long int aLongLongInt; //Long long integer
  
  printf("Size of (short int) = %ld (bytes) %ld bits\n", sizeof(aShortInt), sizeof(aShortInt)*8);
  printf("Size of (int) = %ld (bytes) %ld bits\n", sizeof(aInteger), sizeof(aInteger)*8);
  printf("Size of (long int) = %ld (bytes) %ld bits\n", sizeof(aLongInt), sizeof(aLongInt)*8);
  printf("Size of (long long int) = %ld (bytes) %ld bits\n", sizeof(aLongLongInt), sizeof(aLongLongInt)*8);
  
  return(0);
}