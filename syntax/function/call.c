#include <stdio.h>

void swap(int, int);
void realSwap(int *, int *);

int main(int argc, char *argv[]) {
  int x = 3;
  int y = 6;
  swap(x, y);
  printf("x=%d, y=%d\n", x, y);
  realSwap(&x, &y);
  printf("x=%d, y=%d\n", x, y);
  return 0;
}

void swap(int x, int y) {
  // 此处是传值调用，改变的 x, y 已经不是原地址上的 x, y
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

void realSwap(int *x, int *y) {
  // 此处传入 x,y 的指针，直接根据地址对数据运行交換
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}
