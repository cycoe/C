#include <stdio.h>

#define NUL 0
#define LINE_SIZE 128

// Compare strings
int mystrcmp(const char *s1, const char *s2) {
  // Compare until both strings are NUL
  while (*s1 || *s2) {
    if (*s1 > *s2) {
      return 1;
    } else if (*s1 < *s2) {
      return -1;
    }
    s1++;
    s2++;
  }

  return 0;
}

// Copy from source string to destination with n charactors
unsigned mystrcpy(const char *src, char *dest, unsigned n) {
  unsigned i = 0; // counter
  unsigned copied_n = 0; // amount of charactors that has been copied

  // copy charactors until i == n or source string runs out
  while (i < n && src[i]) {
    dest[i] = src[i];
    i++;
  }
  // record the amount of charactors copied
  copied_n = i;

  // fillup the destination string with NUL
  while (i < n) {
    dest[i] = NUL;
    i++;
  }
  return copied_n;
}

void remove_repeat_line() {
  // line to bear the input line
  char line[LINE_SIZE] = {NUL};
  // buff to bear the previous input line
  char buff[LINE_SIZE] = {NUL};
  // whether the line is a repeated line
  unsigned repeat = 0;

  // read line from stdin
  while (fgets(line, LINE_SIZE, stdin)) {
    // if the line is equal to buff
    if (mystrcmp(line, buff) == 0) {
      // if havent output the line
      // then output it, and set repeat to true
      if (!repeat) {
        printf("%s", line);
        repeat = 1;
      }
    } else {
      // the line is different from the buff line,
      // so update the buff line and set repeat to false
      mystrcpy(line, buff, LINE_SIZE);
      repeat = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  remove_repeat_line();
  return 0;
}
