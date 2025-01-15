#include <stdio.h>

// Morse code arrays for letters
int MORSE_H[4] = {100, 100, 100, 100};  // H
int MORSE_E[1] = {100};                  // E
int MORSE_L[4] = {100, 500, 100, 100};   // L
int MORSE_O[3] = {500, 500, 1000};       // O
int MORSE_W[3] = {100, 500, 500};        // W
int MORSE_R[3] = {100, 500, 100};        // R
int MORSE_D[3] = {500, 100, 100};        // D

int main(void) {
  int result = sizeof(MORSE_L) / sizeof(MORSE_L[0]);
  printf("%d is the integer size of the array", result);
  return (0);
}