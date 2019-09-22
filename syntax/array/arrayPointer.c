#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[10] = {1, 2, 3};
    // 此处也可以不用定义 p，直接使用 *(a + 1) 也可以找到 a 的第二个元素
    // 但用 a 指针本身用左值，所以无法进行自增
    int* p = a;
    // is same as int* p = &a[0];
    printf("%d\n", *(++p));

    // 可以把任意指针当作数组指针使用，进行索引取值
    int b = 1;
    int* q = &b;
    for (int i = 0; i < 10; i++)
        printf("%d\n", q[i]);

    int c[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // 定义数组指针，能够指向含有 4 个 int 变量的数组
    int (*d)[4];
    d = c;
    printf("%d\n", d[2][3]);
    return 0;
}
