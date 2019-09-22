#include <stdio.h>

int main(int argc, char *argv[]) {
    // 以一维方式定义数组，无法通过二维数组的方式获取数据
    /* int a[] = {1, 2, 3, 4, 5, 6}; */
    /* for (int i = 0; i < 2; i++) { */
    /*     for (int j = 0; j < 3; j++) */
    /*         printf("%d\t", a[i][j]); */
    /*     printf("\n"); */
    /* } */

    // 对于 2 维数组，a[0] 是第一个行数组的头指针，a[1] 是第二个头指针
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    int* p = a;
    // a[1] 与 &a[1] 看起来一样，但实际不同
    // a[1] + 1 得到的是 a[1][1] 的地址
    // &a[1] + 1 得到的是 a[2] 的地址
    printf("%d\n", a[1]);
    printf("%d\n", &a[1]);
    printf("%d\n", a[1] + 1);
    printf("%d\n", &a[1] + 1);
    // a 等同于 &a[0]
    printf("%d\n", a);

    // 利用数组连续存储的特点，用一维的方式访问数组
    for (int i = 0; i < 6; i++)
        printf("%d\n", *(*a + i));

    return 0;
}
