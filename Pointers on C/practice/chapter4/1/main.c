#include <stdio.h>

int main(int argc, char *argv[])
{
  double n;
  double ret = 1.0, buff = 0.0;
  unsigned cycle = 0;

  printf("Input a natural number: ");
  scanf("%lf", &n);

  while (ret != buff) {
    buff = ret;
    ret = (ret + n / ret) / 2;
    printf("[%u] Ret: %lf\n", cycle++, ret);
  }

  printf("Complete!\nThe result is %lf\n", ret);
  return 0;
}
