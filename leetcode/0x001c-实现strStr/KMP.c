#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int getStrLen(char * s) {
    int len = 0;
    while (*s) {
        s++;
        len++;
    }
    return len;
}

int * createStates(char * needle, int strSize) {
    int * states = (int *) malloc(sizeof(int) * (strSize << 8));
    memset(states, 0, sizeof(int) << 8);
    states[needle[0]] = 1;

    int X = 0;
    for (int j = 1; j < strSize; j++) {
        for (int c = 0; c < 256; c++) {
            states[(j << 8) + c] = states[(X << 8) + c];
        }
        states[(j << 8) + needle[j]] = j + 1;
        X = states[(X << 8) + needle[j]];
    }
    return states;
}

int strStr(char * haystack, char * needle){
    if (*needle == 0)
        return 0;
    if (*haystack == 0)
        return -1;

    int lenH = getStrLen(haystack);
    int lenN = getStrLen(needle);
    int * states = createStates(needle, lenN);    
    int s = 0;
    for (int i = 0; i < lenH; i++) {
        s = states[(s << 8) + haystack[i]];
        if (s == lenN)
            return i - lenN + 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char * haystack = "needle";
    char * needle = "ed";
    printf("haystack: %s, needle: %s, index: %d\n", haystack, needle, strStr(haystack, needle));
    return 0;
}
