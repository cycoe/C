#include <stdio.h>


int main(int argc, char *argv[])
{
    int a = 1;
    int c;
    c = a++;
    ++a;
    printf("c is %d, a is %d", c, a);

    return 0;
}
