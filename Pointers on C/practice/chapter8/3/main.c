#include <stdio.h>

unsigned identity_matrix(int matrix[][10], unsigned size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == j) {
        if (matrix[i][j] != 1)
          return 0;
      } else {
        if (matrix[i][j] != 0)
          return 0;
      }
    }
  }

  return 1;
}

int main(int argc, char *argv[])
{
  int matrix[10][10] = {{1}, {0, 1}};
  printf("matrix is %sa I.\n", identity_matrix(matrix, 10) ? "" : "Not ");
  return 0;
}
