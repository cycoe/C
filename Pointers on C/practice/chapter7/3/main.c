#include <stdio.h>


int ascii_to_integer(const char *string) {
  unsigned ret = 0;
  while (*string) {
    if (*string < '0' || *string > '9')
      return 0;

    ret = ret * 10 + (*string - '0');
    string++;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  char *string = "1239128";
  printf("[%s] is %d\n", string, ascii_to_integer(string));
  return 0;
}
