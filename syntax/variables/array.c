#include <stdio.h>


int main(int argc, char *argv[])
{
    int arr[] = {1, 2};
    int *p = arr;
    *(p + 1) = 10;
    printf("%d\n", arr[1]);

    p = &arr[0];
    *(p + 1) = 20;
    printf("%d\n", arr[1]);

    return 0;
}
