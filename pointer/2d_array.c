#include <stdio.h>


void min(int (*a)[4], int m) {
    int value, i, j;
    for (i = 0; i < m; i++) {
        value = *(*(a + i));
        for (j = 1; j < 4; j++) {
            if (*(*(a + i) + j) < value)
                value = *(*(a + i) + j);
        }
        printf("Line %d, min number is %d\n", i, value);
    }
}

void print_2d(int** a, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("row %d, col %d: %d\n", i, j, *(*(a + i) + j));
        }
    }
}

void print_1d(int* a, int m) {
    int i;
    for (i = 0; i < m; i++) {
        printf("row %d: %d\n", i, *(a + i));
    }
}


int main(int argc, char *argv[])
{
    int a1[4] = {1, 2, 3, 4};
    // 以 int a[4] 这种方式定义数组，a 指向数组的第一个变量
    print_1d(a1, 4);
    // 但与指向第一个变量的指针不一样，a 中还儲存了数组的长度，即数组占用的内存
    printf("size of a1: %d\n", sizeof(a1));
    // 但如果将 a 赋值给一个指针，或者调用了指针运算，则 sizeof 得到的是指针变量占用的内存
    int* p = a1;
    printf("size of p: %d\n", sizeof(p));
    printf("size of a1: %d\n", sizeof(a1 + 1));

    // 定义了 3 个数组，并定义了一个指针数组，数组中的每个变量都是一个指向数组的指针
    int a2[4] = {5, 6, 7, 8};
    int a3[4] = {9, 10, 11, 12};
    int *a[3] = {a1, a2, a3};
    // a 的 size 其实就是 3 个指针占用的内存
    printf("size of a: %d\n", sizeof(a));
    // 此处的 a 可以视一个二阶指针，指向 a1，即 a 数组中儲存的值，是 a1, a2, a3 的头指针
    int** p2 = a;
    print_2d(p2, 3, 4);
    // 由于 a 是指向指针的指针，因此 a++ 的偏移量是一个指针的长度，即 8 字节
    printf("p2: %p\n", p2);
    p2++;
    printf("p2: %p\n", p2);

    int b[2][3] = {1, 2, 3, 4, 5, 6};
    // 有的时候，即使两个指针指向的地址是一样的，但由于指针的类型是不同的，含义也不同
    printf("pointer b: %p\n", b);
    printf("pointer b[0]: %p\n", b[0]);
    // 此处的 b 不可视为二阶指针，虽然强行赋值不报错
    /* int** p3 = b; */
    // 而是定义一个指针，指向长度为 3 的 int 型数组
    int (*p3)[3] = b;
    // 因为指向的是长度为 3 的 int 型数组，因此偏移量为 12 个字节
    printf("p3: %p\n", p3);
    p3++;
    printf("p3: %p\n", p3);

    return 0;
}
