/**
 * Find the key number in an array.
*/
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 7 // Size of the array to search

int main(){
  // Array to search
  int array[ARRAY_SIZE] = {4, 5, 23, 56, 79, 0, -5};
  static const int KEY = 56; // Key to search for 

  for (unsigned int index = 0; index < ARRAY_SIZE; ++index) {
    if (array[index] == KEY) {
      printf("Key (%d) found at index %d\n", KEY, index);
      break;
    }
  }
  return (0);
}