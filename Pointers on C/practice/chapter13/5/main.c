#include <stdio.h>

static int in_control(int ch, char *control) {
  while (*control) {
    /* 不是选项返回 0，需要参数返回 2，不需要参数返回 1 */
    if (ch == *control)
      return *(control + 1) == '+' ? 2 : 1;
    control++;
  }
  return 0;
}

char **do_args(int argc, char **argv, char *control,
               void (*do_arg)(int ch, char *value),
               void (*illegal_arg)(int ch)) {

  /* 存储参数段 */
  char *section;
  int control_type;

  /* 跳过程序名，遍历以 '-' 开头的参数段 */
  while (*++argv && **argv == '-') {
    section = *argv;
    /* 遍历参数段的参数 */
    while (*++section) {
      if ((control_type = in_control(*section, control)) == 2) {
        /* 如果参数在参数集中，并且需要附带参数 */
        if (*(section + 1)) {
          /* 如果该参数段后续还有参数，将其作为附加参数 */
          do_arg(*section, section + 1);
        } else if (*(argv + 1)) {
          /* 否则如果还有下一个参数段，则将下一个参数段作为附加参数，并且 ++argv
           */
          do_arg(*section, *++argv);
        } else {
          /* 否则该参数非法 */
          illegal_arg(*section);
        }
        /* 以上三种情况都需要跳过对本参数段后续参数的处理 */
        break;
      } else if (control_type == 1) {
        /* 参数在参数集中，但是不需要附加参数，直接处理此参数 */
        do_arg(*section, NULL);
      } else {
        /* 不在参数集中的为非法参数 */
        illegal_arg(*section);
      }
    }
  }

  return argv;
}

void do_arg(int ch, char *value) {
  printf("[do] parameter is %c, value is %s\n", ch, value);
}

void illegal_arg(int ch) { printf("[illegal] parameter is %c\n", ch); }

int main(int argc, char *argv[])
{
  char control[100] = "ab+cdef+g";
  char **ret = do_args(argc, argv, control, do_arg, illegal_arg);
  printf("next section is %s\n", *ret);
  return 0;
}
