#include <stdio.h>

long count;

void move(int, char, char, char);

int main(int argc, char *argv[]) {
  count = 0;
  int n = 0;
  move(3, 'a', 'b', 'c');
  return 0;
}

void move(int n, char a, char b, char c) {
  if (n == 1)
    printf("Times: %d\t%c->%c\n", ++count, a, c);
  else {
    // 把 n-1 层从 a 移到 b
    move(n - 1, a, c, b);
    printf("Times: %d\t%c->%c\n", ++count, a, c);
    // 把 n-1 层从 b 移到 c
    move(n - 1, b, a, c);
  }
}
