/* 实现 strStr() 函数。 */

/* 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。 */

/* 示例 1: */

/* 输入: haystack = "hello", needle = "ll" */
/* 输出: 2 */

/* 示例 2: */

/* 输入: haystack = "aaaaa", needle = "bba" */
/* 输出: -1 */

/* 说明: */

/* 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 */

/* 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/implement-strstr */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int getStrLen(char * s) {
    int len = 0;
    while (*s != 0) {
        s++;
        len++;
    }
    return len;
}

int * createStates(char * needle, int strSize) {
    int * states = (int *) malloc(sizeof(int) * (strSize << 8));
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
