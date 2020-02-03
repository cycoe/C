#include <stdio.h>
#include <ctype.h>

enum Counter {
  cntrl = 0,
  space = 1,
  digit = 2,
  lower = 3,
  upper = 4,
  punct = 5,
  print = 6
};

int (*check[7])(int) = {iscntrl, isspace, isdigit, islower,
  isupper, ispunct, isprint};

unsigned *count_charactors(const char *string, unsigned counter[]) {
  if (string == NULL)
    return counter;

  while (*string) {
    for (register int i = 0; i < 7; i++) {
      if (check[i](*string)) {
        counter[i]++;
      }
    }
    string++;
  }

  return counter;
}

int main(int argc, char *argv[])
{
  unsigned counter[7] = {0};
  count_charactors("shua sia121HSHAU", counter);
  for (int i = 0; i < 7; i++) {
    printf("%d ", counter[i]);
  }

  return 0;
}
