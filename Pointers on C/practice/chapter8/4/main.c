#include <stdio.h>

unsigned identity_matrix(int *matrix, unsigned size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        if (matrix[i * size + j] != 1)
          return 0;
      } else {
        if (matrix[i * size + j] != 0)
          return 0;
      }
    }
  }

  return 1;
}

int main(int argc, char *argv[])
{
  int matrix[3][3] = {{1}, {0, 1}, {0, 0, 1}};
  printf("matrix is %sa I.\n", identity_matrix(*matrix, 3) ? "" : "Not ");
  return 0;
}
