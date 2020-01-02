#include <stdio.h>

int main(int argc, char *argv[]) {
  // ring bell
  printf("\a");
  // horizontal table character
  printf("1\t2\t3\n");
  // vertical table character
  // back character
  printf("\t4\v\b5\v\b6\n");
  // return character
  char buf[4] = {0};
  for (int i = 0; i < 3; i++) {
    buf[i] = 'a' + i;
    printf("%s", buf);
    if (i != 2)
      printf("\r");
  }
    return 0;
}
