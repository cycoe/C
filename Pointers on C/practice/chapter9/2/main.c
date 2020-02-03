#include <stdio.h>
#include <string.h>

#define NUL 0

unsigned long my_strlen(const char *string, unsigned size) {
  unsigned long length;

  for (length = 0; length < size; length++) {
    if (*string++ == NUL) {
      break;
    }
  }

  return length;
}

int main(int argc, char *argv[]) {
  char string[10];
  strncpy(string, "My name is cycoe", 10);

  // count length with strlen
  printf("Length is %lu.\n", strlen(string));

  // count length with my strlen
  printf("Length is %lu.\n", my_strlen(string, 10));
  return 0;
}
