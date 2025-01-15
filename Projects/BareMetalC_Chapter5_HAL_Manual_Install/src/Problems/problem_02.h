/*
 * A program counting the number of bits that are set in a uint32_t integer. For example, the mumber 0x0000A0 has 2 bits
 * in it as per 0000 0000 0000 00001010 base 2 or 10 base10
*/
#include <stdio.h>

int bitCounter(unsigned int source_val){
  int count = 0;
  while (source_val) {
    count += source_val & 1;
    source_val >>= 1;
  }
  return count;
}


int main() {
  unsigned int param_val;
  printf("Enter a hexadecimal number (example: 0x1F): ");
  scanf("%x", &param_val);
  int totalBitCount = bitCounter(param_val);
  printf("The number of set bits in 0x%X is: %d\n", param_val, totalBitCount);
  return 0;
}
