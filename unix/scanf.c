#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int flag, num;
  // if scanf execute successfully, it returns 1, otherwise returns 0
  printf("Input a number:");
  flag = scanf("%d", &num);
  printf("flag: %d; num: %d\n", flag, num);
  return 0;
}
