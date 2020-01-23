#include <stdio.h>

int gcd_helper(int a, int b) {
  if (a % b == 0)
    return b;

  return gcd_helper(b, a % b);
}

int gcd(int a, int b) {
  if (a <= 0 || b <= 0)
    return 0;

  return gcd_helper(a, b);
}

int main(int argc, char *argv[]) {
  int a = 748197237;
  int b = 247281747;
  printf("gcd(%d, %d) is %d\n", a, b, gcd(a, b));
  return 0;
}
