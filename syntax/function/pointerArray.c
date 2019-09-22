#include <stdio.h>

int main(int argc, char *argv[])
{
    int *p[4];
    int a = 1;
    p[0] = &a;
    printf("%d\n", *p[0]);
    return 0;
}
