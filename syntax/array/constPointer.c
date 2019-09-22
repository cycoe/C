#include <stdio.h>

int main(int argc, char *argv[]) {
    // 定义指针常量，指针的值无法修改
    int i = 3, a = 0;
    int* const p = &i;
    /* p = &a; */
    *p = 4;

    // 定义指向常量的指针
    // 无法通过 *q = 4 来 i 的值进行修改
    // 但可以直接通过 i = 4 进行修改
    int const* q = &i;
    /* *q = 4; */
    i = 4;

    // 指向常量的指针常量
    int const* const r = &i;

    return 0;
}
