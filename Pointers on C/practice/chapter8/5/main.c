#include <stdio.h>
void matrix_multiply(int *m1, int *m2, int *r, unsigned x, unsigned y,
                     unsigned z) {
  for (int i = 0; i < x; i++) {
    for (int k = 0; k < z; k++) {
      r[i * z + k] = 0;
      for (int j = 0; j < y; j++) {
        r[i * z + k] += m1[i * y + j] * m2[j * z + k];
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int m1[3][2] = {2, -6, 3, 5, 1, -1};
  int m2[2][4] = {4, -2, -4, -5, -7, -3, 6, 7};
  int r[3][4] = {0};
  matrix_multiply(*m1, *m2, *r, 3, 2, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d, ", r[i][j]);
    }
    printf("\n");
  }
  return 0;
}
