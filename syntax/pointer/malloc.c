#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // 对于 C 而言，使用 malloc 分配动态内存，使用 free 释放内存
    int* p1 = NULL;
    p1 = (int*) malloc(4);
    *p1 = 111;
    printf("*p1: %p, p1: %d\n", p1, *p1);
    free(p1);
    printf("*p1: %p, p1: %d\n", p1, *p1);
    p1 = NULL;

    int* p2;
    int k;
    p2 = &k;
    *p2 = 222;
    printf("*p2: %p, p2: %d\n", p2, *p2);
    return 0;
}
