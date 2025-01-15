/**
 * Find the key number in an array.
*/
#include <stdio.h>
#define COMMAND_COUNT 5 // Number of commands

// Commands, ones beginning with . are secret
static const char commands[COMMAND_COUNT][5] = {
  "help",
  "exec",
  ".adm",
  "quit"
};
int main() {
  // Print the help text
  for (unsigned int index = 0; index < COMMAND_COUNT; ++index) {
    if (commands[index][0] == '.') {
      // Hidden command
      continue;
    }
    printf("%s\n", commands[index]);
  }
  return (0);
}