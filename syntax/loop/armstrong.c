#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    for (int input=100; input < 10000; input++) {
        int sum = 0, flag = input;
        while (flag) {
            int num = flag % 10;
            sum += num*num*num*num;
            flag /= 10;
        }
        if (sum == input)
            printf("%d\n", input);
    }
    return 0;
}
