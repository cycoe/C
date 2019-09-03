#include <stdio.h>

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    printf("%d\n", a[i]);
  }

  // 当聚合赋值的长度比数组定义长度小时
  // 后面会被自动赋值 0
  int b[5] = {1, 2, 3};
  printf("%d\n", b[4]);

  // 数组越界并不会报错，但会输出意想不到的结果
  printf("%d\n", b[5]);

  printf("================\n");
  int array[2][3] = {
      1, 2, 3, 4, 5, 6,
  };
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d\t", array[i][j]);
    printf("\n");
  }

  printf("================\n");
  // 二维数组赋值时，每一行的元素都可以不足，会自动补 0
  int c[2][3] = {{1, 2, 3}, {4}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d\t", c[i][j]);
    printf("\n");
  }

  return 0;
}
