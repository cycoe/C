#include <stdio.h>
// you have to include this header to use bool type
#include <stdbool.h>


void main() {
    bool ret;
    int var = 3;
    ret = var;
    printf("ret is %d\n", ret);
    var = ret;
    printf("var is %d\n", var);
}
