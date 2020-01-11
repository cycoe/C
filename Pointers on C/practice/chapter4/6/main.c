#include <stdio.h>

#define NUL 0

int substr(char dest[], char src[], int start, int len) {
  if (start < 0 || len < 0) {
    dest[0] = NUL;
    return 0;
  }

  // move pointer of src to offset start
  for (int i = 0; i < start; i++) {
    if (src[i] == NUL) {
      dest[0] = NUL;
      return 0;
    }
  }

  // start to copy substring
  int j = 0;
  while (j < len && src[start + j]) {
    dest[j] = src[start + j];
    j++;
  }
  dest[j] = NUL;
  return j;
}

int main(int argc, char *argv[])
{
  char dest[100] = {NUL};
  char src[100] = "My name is Cycoe.";
  substr(dest, src, 2, 7);
  printf("result is: %s\n", dest);
  return 0;
}
