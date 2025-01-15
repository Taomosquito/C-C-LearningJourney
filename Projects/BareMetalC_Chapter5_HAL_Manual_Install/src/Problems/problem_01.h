/**
 * A program showing the multiplication table for numbers 0 x 0 to  9 x 9.
*/
#include <stdio.h>

#define PEAK_COUNT 9
#define OVERPEAK_COUNT 10

int main() {
  int first_number = 0; // Initialize the first number
  int second_number = 0; // Initialize the second number

  while (first_number < OVERPEAK_COUNT) {
    printf("%d x %d = %d\n", first_number, second_number, first_number * second_number);
    
    // When second_number reaches PEAK_COUNT, reset it and increment first_number
    if (second_number == PEAK_COUNT) {
      ++first_number;
      second_number = 0; // Reset second_number for the next row      
    } else {
      ++second_number;
    }
  }

  return 0;
}
