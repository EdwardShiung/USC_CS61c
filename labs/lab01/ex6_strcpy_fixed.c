#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // TODO: Create space to store the string "hello"
  // You may use your solution from a previous exercise;
  char message[6];
  message[0] = 'h';
  message[1] = 'e';
  message[2] = 'l';
  message[3] = 'l';
  message[4] = 'o';
  message[5] = '\0';

  // Print out the value before we change message
  printf("Before copying: %s\n", message);

  // Creates another_string that contains a longer string
  char* long_message = "Here's a really long string";

  // TODO: Copy the string in long_message to message
  strncpy(message, long_message, sizeof(message) - 1);
  /**
   * Using strncpy can prevent the overflow” is true only if you use it correctly
   * As written (strncpy(message, long_message, sizeof(message))), message may end up without a null terminator when the source is longer than or equal to 6. 
   * That leads to undefined behavior when you print it with %s.
   * 
   * Bonus on macOS:
   * strlcpy(message, long_message, sizeof(message)); always null-terminates and is simpler.
   * 
   * https://web.archive.org/web/20241231143451/https://cplusplus.com/reference/cstring/strncpy/ 
   * 
   */


  // Print out the value after we change message
  printf("After copying: %s\n", message);

  return 0;
}
