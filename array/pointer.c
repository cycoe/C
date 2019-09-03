#include <stdio.h>

int main(int argc, char *argv[]) {
    // 输出指针
    int a = 0;
    int* p = &a;
    printf("%x\n", p);
    printf("size of int is %d\n", sizeof(int));
    printf("size of a is %d\n", sizeof(a));
    printf("size of p is %d\n", sizeof(p));
    return 0;
}
