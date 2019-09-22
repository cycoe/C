#include <stdio.h>

int add(int x, int y);

int main(int argc, char *argv[]) {
  int x = 10, y = 10;
  printf("%d\n", add(x, y));
  // 此处定义了一个函数指针
  // 最开头 int 表示函数返回值的类型
  // (*p) 的括号一定要有，否则会提示 ‘function ‘p’ is initialized like a variable’
  // (int x, int y) 中的形参名可以省略
  int (*p)(int, int) = add;
  /* int (*p)(int x, int y) = add; */
  printf("%d\n", p(x, y));
  // 此处的 * 可有可无
  printf("%d\n", (*p)(x, y));
  return 0;
}

int add(int x, int y) { return x + y; }
