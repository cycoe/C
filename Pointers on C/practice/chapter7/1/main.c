#include <stdio.h>

int hermite(int n, int x) {
  // hermite polynomials
  if (n <= 0) {
    return 1;
  }
  if (n == 1) {
    return 2 * x;
  }
  return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main(int argc, char *argv[]) {
  int n = 3;
  int x = 2;
  printf("H_%d(%d) is %d\n", n, x, hermite(n, x));
  return 0;
}
