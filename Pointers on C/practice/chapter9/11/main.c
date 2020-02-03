#include <stdio.h>
#include <string.h>

char whitespace[] = " \n\r\f\t\v";

unsigned count_word(char *string, const char *word) {
  unsigned count = 0;
  char *buff;

  // strtok with replace separator with NUL, the return the pointer to the
  // string before separator.
  // if the first parameter is NULL, strtok with continue the last string
  for (buff = strtok(string, whitespace); buff != NULL;
       buff = strtok(NULL, whitespace)) {
    if (strcmp(buff, word) == 0)
      count++;
  }

  return count;
}

int main(int argc, char *argv[])
{
  char buff[101];
  unsigned count = 0;
  while (fgets(buff, 100, stdin)) {
    count += count_word(buff, "the");
  }
  printf("%u\n", count);
  return 0;
}
