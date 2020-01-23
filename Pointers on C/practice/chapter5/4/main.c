#include <stdio.h>

void set_bit(char bit_array[], unsigned bit_number) {
  // Set the bit_number bit to 1
  bit_array[bit_number] = 1;
}

void clear_bit(char bit_array[], unsigned bit_number) {
  // Set the bit_number bit to 0
  bit_array[bit_number] = 0;
}

void assign_bit(char bit_array[], unsigned bit_number, int value) {
  bit_array[bit_number] = value ? 1 : 0;
}

int test_bit(char bit_array[], unsigned bit_number) {
  return bit_array[bit_number] ? 1 : 0;
}
