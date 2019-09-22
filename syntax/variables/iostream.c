#include <stdio.h>


int main(int argc, char *argv[])
{
    printf("print your age: ");
    int age;
    scanf("%d", &age);
    printf("Your age is %d.", age);

    printf("print your name: ");
    char name[20];
    scanf("%s", name);
    printf("\nYour name is %s.", name);

    return 0;
}
