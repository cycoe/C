#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define LEN 4500

char * countAndSay(int n){
    unsigned int bytes = sizeof(char) * LEN;
    char * tmp = (char *) malloc(bytes);
    char * ret = (char *) malloc(bytes);
    char * t;
    memset(tmp, 0, bytes);
    memset(ret, 0, bytes);

    tmp[0] = '1';
    ret[0] = '1';
    char c;
    int num;
    int ri;
    int ti;
    for (int row = 1; row < n; row++) {
        t = tmp;
        tmp = ret;
        ret = t;

        num = 1;
        ri = 0;
        ti = 1;
        c = tmp[0];
        while (tmp[ti]) {
            if (c == tmp[ti])
                num++;
            else {
                ret[ri++] = num + '0';
                ret[ri++] = c;
                num = 1;
                c = tmp[ti];
            }
            ti++;
        }
        ret[ri++] = num + '0';
        ret[ri++] = c;
    }
    free(tmp);
    return ret;
}

int main(int argc, char *argv[])
{
    char * s = countAndSay(30);
    printf("%s\n", s);
    free(s);
    return 0;
}
