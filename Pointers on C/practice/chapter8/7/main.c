#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>

int arrar_offset_helper(int arrayinfo[], va_list ap, int d) {
  if (d == arrayinfo[0]) {
    return 0;
  }

  int s = va_arg(ap, int);
  int lo = arrayinfo[(d << 1) + 1];
  int hi = arrayinfo[(d + 1) << 1];
  if (s < lo || s > hi) {
    printf("Location is out of range!\ns is %d, lo is %d, hi is %d.\n", s, lo,
           hi);
    return -1;
  }

  int offset = arrar_offset_helper(arrayinfo, ap, d + 1);
  return offset == -1 ? offset :offset * (hi - lo + 1) + s - lo;
}

int array_offset2(int arrayinfo[], ...) {
  // Check the dimension
  if (arrayinfo[0] < 1 || arrayinfo[0] > 10) {
    printf("Dimension is out of range!\n");
    return -1;
  }

  unsigned offset;
  va_list ap;
  va_start(ap, arrayinfo);
  offset = arrar_offset_helper(arrayinfo, ap, 0);
  va_end(ap);

  return offset;
}

int main(int argc, char *argv[])
{
  int arrayinfo[7] = {3, 4, 6, 1, 5, -3, 3};
  printf("Offset is %d\n", array_offset2(arrayinfo, 6, 5, 3));
  return 0;
}
