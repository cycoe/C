#include <stdio.h>
#include <unistd.h>

#define THOUSAND 1e3
#define MILLION 1e6
#define BILLION 1e9

char *my_strcpy(char *dest, const char *src) {
  while (*src) {
    *dest++ = *src++;
  }

  return dest;
}

char *written_amount(unsigned amount, char *buff) {
  if (amount > 0 && amount <= 9) {
    switch (amount) {
    case 1:
      buff = my_strcpy(buff, "one");
      break;
    case 2:
      buff = my_strcpy(buff, "two");
      break;
    case 3:
      buff = my_strcpy(buff, "three");
      break;
    case 4:
      buff = my_strcpy(buff, "four");
      break;
    case 5:
      buff = my_strcpy(buff, "five");
      break;
    case 6:
      buff = my_strcpy(buff, "six");
      break;
    case 7:
      buff = my_strcpy(buff, "seven");
      break;
    case 8:
      buff = my_strcpy(buff, "eight");
      break;
    case 9:
      buff = my_strcpy(buff, "nine");
      break;
    }
    return buff;
  } else if (amount >= 10 && amount <= 19) {
    switch (amount) {
    case 10:
      buff = my_strcpy(buff, "ten");
      break;
    case 11:
      buff = my_strcpy(buff, "eleven");
      break;
    case 12:
      buff = my_strcpy(buff, "twelve");
      break;
    case 13:
      buff = my_strcpy(buff, "thirteen");
      break;
    case 14:
      buff = my_strcpy(buff, "fourteen");
      break;
    case 15:
      buff = my_strcpy(buff, "fifteen");
      break;
    case 16:
      buff = my_strcpy(buff, "sixteen");
      break;
    case 17:
      buff = my_strcpy(buff, "seventeen");
      break;
    case 18:
      buff = my_strcpy(buff, "eighteen");
      break;
    case 19:
      buff = my_strcpy(buff, "nineteen");
      break;
    }
  } else if (amount >= 20 && amount <= 99) {
    switch ((int)amount / 10) {
    case 2:
      buff = my_strcpy(buff, "twenty ");
      break;
    case 3:
      buff = my_strcpy(buff, "thirty ");
      break;
    case 4:
      buff = my_strcpy(buff, "forty ");
      break;
    case 5:
      buff = my_strcpy(buff, "fifty ");
      break;
    case 6:
      buff = my_strcpy(buff, "sixty ");
      break;
    case 7:
      buff = my_strcpy(buff, "seventy ");
      break;
    case 8:
      buff = my_strcpy(buff, "eighty ");
      break;
    case 9:
      buff = my_strcpy(buff, "ninety ");
      break;
    }
    buff = written_amount(amount % 10, buff);
  } else if (amount >= 100 && amount < 1e3) {
    buff = written_amount((int)amount / 100, buff);
    buff = my_strcpy(buff, " hundred ");
    buff = written_amount(amount % 100, buff);
  } else if (amount >= 1000 && amount < 1e6) {
    buff = written_amount((int)amount / 1000, buff);
    buff = my_strcpy(buff, " thousand ");
    buff = written_amount(amount % 1000, buff);
  } else if (amount >= 1e6 && amount < 1e9) {
    buff = written_amount((int)amount / 1e6, buff);
    buff = my_strcpy(buff, " million ");
    buff = written_amount(amount % 1000000, buff);
  } else if (amount >= 1e9) {
    buff = written_amount((int)amount / 1e9, buff);
    buff = my_strcpy(buff, " billion ");
    buff = written_amount(amount % 1000000000, buff);
  }

  return buff;
}

int main(int argc, char *argv[])
{
  if (argc == 2) {
    unsigned amount;
    if ((sscanf(argv[1], "%u", &amount) != 1)) {
      printf("Not a Integer!\n");
      return 127;
    }
    char buff[4096] = {0};
    written_amount(amount, buff);
    printf("%s\n", buff);
    return 0;
  } else {
    printf("Usage: ./main [amount]\n");
    return 127;
  }
}
