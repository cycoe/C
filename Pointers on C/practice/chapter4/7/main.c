#include <stdio.h>

#define NUL 0
#define SPACE ' '

void deblank(char *string) {
  // 储存前一个字符用于判断是否是相连的空格
  char previous = 0;
  unsigned fast = 0, slow = 0;
  while (string[fast]) {
    // 如果快指针是空格并且前一次的字符也是空格
    // 说明出现连续空格
    if (string[fast] == SPACE && previous == SPACE) {
      fast++;
    } else {
      previous = string[fast];
      string[slow++] = string[fast++];
    }
  }
  string[slow] = NUL;
}

int main(int argc, char *argv[])
{
  char string[100] = "My name is     Cycoe.";
  deblank(string);
  printf("Result is: %s\n", string);
  return 0;
}
