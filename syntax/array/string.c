#include <stdio.h>

int main(int argc, char *argv[]) {
    // 声明固定长度的字符串数组
    char a[11] = {'H', 'e', 'l', 'l', 'o'};
    printf("%s\n", a);
    for (int i = 0; i < 30; i++) {
        if (a[i] == '\0') {
            printf("The %d char is \\0\n", i);
            break;
        }
    }

    // 聚合方式赋值
    char b[] = {'H', 'e', 'l', 'l', 'o'};
    // 数组 b 的长度与聚合的长度相同，因此末尾没有 \0
    printf("%s\n", b);
    for (int i = 0; i < 30; i++) {
        if (b[i] == '\0') {
            printf("The %d char is \\0\n", i);
            break;
        }
    }
    // let b[5] = '\0', and string handler know where to stop.
    b[5] = '\0';
    printf("%s\n", b);

    // c[] = "Hello" 与 c[] = "Hello\0" 相同
    char c[] = "Hello";
    printf("%s\n", c);

    // 使用指数给数组赋值
    char* d = "Hello";
    printf("%s\n", d);

    // 利用指针操作数组
    char* p = b;
    for (int i = 0; i < 5; i++)
        printf("%c\n", *(p + i));
  return 0;
}
