#include <stdio.h>
#include <stdarg.h>

int max_list(int num, ...) {
  int max = num;
  int buff = num;

  // va list
  va_list argv;
  // initiate an va list with first parameter
  va_start(argv, num);

  while ((buff = va_arg(argv, int)) >= 0) {
    if (buff > max) {
      max = buff;
    }
  }

  // don't forget to close a va list
  va_end(argv);

  return max;
}

int main(int argc, char *argv[])
{
  printf("max is %d\n", max_list(1, 2, 3, 4, 8, 1, -1));
  return 0;
}
