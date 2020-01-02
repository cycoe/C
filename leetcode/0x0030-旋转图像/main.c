#include <malloc.h>
#include <memory.h>
#include <stdio.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
  // 用来交换数字的临时变量
  int buffer = 0;

  // 矩阵的半宽
  int half = matrixSize >> 1;
  // i 的轴对称
  int symI;
  // j 的轴对称
  int symJ;

  // 由外向內逐层处理
  for (int i = 0; i < half; i++) {
    symI = matrixSize - i - 1;
    for (int j = i; j < symI; j++) {
      symJ = matrixSize - j - 1;
      // 中心对称的 4 个变量顺时针旋转
      buffer = matrix[i][j];
      matrix[i][j] = matrix[symJ][i];
      matrix[symJ][i] = matrix[symI][symJ];
      matrix[symI][symJ] = matrix[j][symI];
      matrix[j][symI] = buffer;
    }
  }
}

int main(int argc, char *argv[]) {
  int a[3] = {1, 2, 3};
  int b[3] = {4, 5, 6};
  int c[3] = {7, 8, 9};
  int *matrix[3] = {a, b, c};
  int matrixColSize[3] = {3, 3, 3};
  rotate(matrix, 3, matrixColSize);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d, ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
