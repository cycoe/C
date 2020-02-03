#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>

int array_offset(int arrayinfo[], ...) {
  // Check the dimension
  if (arrayinfo[0] < 1 || arrayinfo[0] > 10) {
    printf("Dimension is out of range!\n");
    return -1;
  }

  unsigned offset = 0;
  int s, lo, hi;
  va_list ap;
  va_start(ap, arrayinfo);

  for (unsigned d = 0; d < arrayinfo[0]; d++) {
    s = va_arg(ap, int);
    lo = arrayinfo[(d << 1) + 1];
    hi = arrayinfo[(d + 1) << 1];

    if (s < lo || s > hi) {
      va_end(ap);
      printf("Location is out of range!\ns is %d, lo is %d, hi is %d.\n", s, lo,
             hi);
      return -1;
    }

    offset = offset * (hi - lo + 1) + s - lo;
  }

  va_end(ap);
  return offset;
}

int main(int argc, char *argv[])
{
  int arrayinfo[7] = {3, 4, 6, 1, 5, -3, 3};
  printf("Offset is %d\n", array_offset(arrayinfo, 6, 3, 1));
  return 0;
}
