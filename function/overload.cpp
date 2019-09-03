#include <stdio.h>

// 只有 C++ 支持重载，而 C 不支持
int add(int, int);
float add(float, float);

int main(int argc, char *argv[]) {
  int intC = add(1, 2);
  // 此处应特别注意
  // 在 C 中，float 型运算时会自动转为 double 型
  // 要么用 (float) 强制类型转换，要么在定义函数的时候使用 double
  float floatC = add((float)1.1, (float)2.2);
  printf("int add: %d\n", intC);
  printf("float add: %f\n", floatC);
  return 0;
}

int add(int x, int y) { return x + y; }

float add(float x, float y) { return x + y; }
