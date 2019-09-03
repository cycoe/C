#include <stdio.h>


int main(int argc, char *argv[])
{
    int a = 1;
    printf("%d %d\n", a, &a);
    printf("%d", *(&a + 1));

    int *p = &a;
    int b = *p;
    printf("\nb is %d", b);

    return 0;
}
