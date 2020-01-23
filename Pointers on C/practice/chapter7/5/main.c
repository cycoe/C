#include <stdarg.h>
#include <stdio.h>

void print_integer(const char *string, int num) { printf(string, num); }

void print_float(const char *string, float num) { printf(string, num); }

void my_printf(const char *string, ...) {
  unsigned format = 0;
  const char *buff;

  va_list argv;
  va_start(argv, string);

  while (*string) {
    if (format) {
      switch (*string) {
      case 'd':
        print_integer("%d", va_arg(argv, int));
        break;
      case 'f':
        print_float("%f", va_arg(argv, double));
        break;
      case 's':
        buff = va_arg(argv, char *);
        while (*buff) {
          putchar(*buff++);
        }
        break;
      case 'c':
        putchar(va_arg(argv, int));
        break;
      case '%':
        putchar('%');
        break;
      default:
        break;
      }
      format = 0;
    } else {
      if (*string == '%')
        format = 1;
      else {
        putchar(*string);
      }
    }

    string++;
  }

  va_end(argv);
}

int main(int argc, char *argv[])
{
  my_printf("my name is %s, age is %d", "Cycoe", 24);
  return 0;
}
