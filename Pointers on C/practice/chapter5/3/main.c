#include <stdio.h>
#include <limits.h>

unsigned reverse_bits(unsigned value) {
  unsigned len = sizeof(unsigned) * 8;
  unsigned ret = 0;
  for (int i = 0; i < len; i++) {
    ret <<= 1;
    ret |= value & 0x1;
    value >>= 1;
  }

  return ret;
}

void print_bin(unsigned value, unsigned len) {
  if (!len) {
    return;
  }

  print_bin(value >> 1, len - 1);
  printf("%u", value & 0x1);
}

int main(int argc, char *argv[]) {
  unsigned value = 0x13;
  unsigned len = sizeof(unsigned) * 8;
  printf("Origin is: ");
  print_bin(value, len);
  printf("\nReverse is: ");
  print_bin(reverse_bits(value), len);
  return 0;
}
