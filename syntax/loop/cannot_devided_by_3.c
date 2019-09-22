#include <stdio.h>


int main(int argc, char *argv[])
{
    for (int i=0; i<=100; i++)
        if (i%3)
            printf("%d\n", i);

    return 0;
}
