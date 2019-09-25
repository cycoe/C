#include <stdio.h>
#include <malloc.h>

#define MIN(a,b) ((a)<(b))?(a):(b)

// 获取字符串有效部分的长度
unsigned int getLength(char * s) {
    int len = 0;
    while (*s != '\0') {
        ++len;
        ++s;
    }
    return len;
}

// 生成预处理字符串
char * gen_string(char * s, unsigned int len) {
    // 为生成的预处理字符串分配内存
    // 若原字符串长度为 len，则插入 # 号的个数为 len + 1
    // 再加上 ^ 与 $ 两个符号，新字符串的总长度为 2 * len + 3
    // ababa -> ^#a#b#a#b#a#$
    char * ret = (char *) malloc(sizeof(char) * ((len << 1) + 3));
    for (int i = 0; i < len; i++) {
        ret[(i << 1) + 2] = s[i];
        ret[(i << 1) + 3] = '#';
    }
    ret[0] = '^';
    ret[1] = '#';
    ret[(len << 1) + 2] = '$';
    return ret;
}

// 查找最长回文子串
char * longestPalindrome(char * s){
    int len = getLength(s);

    // 如果 s 是空字符串，则直接返回一个空字符串
    // 其实可以直接返回 s，但为了行为的一致性，返回一块堆内存
    if (len == 0) {
        char * ret = (char *) malloc(sizeof(char));
        // 初始化非常重要，否则默认是 '\256'
        *ret = 0;
        return ret;

    }

    // 生成预处理字符串
    char * t = gen_string(s, len);
    // 更新长度为预处理字符串的长度
    len = (len << 1) + 3;

    int C = 0;    // 回文中心索引
    int R = 0;    // 回文右边界索引
    int maxI = 0; // 最长回文中心索引
    int maxP = 0; // 最长回文长度
    // 分配内存给回文长度数组
    int * P = (int *) malloc(sizeof(int) * len);

    for (int i = 1; i < len - 1; i++) {
        int j = (C << 1) - i;
        // 初始化 P[i] 的值
        if (R > i)
            // 如果 i < R，复制镜像
            // 但若 P[j] + i > R，则说明 P[j] + i 已经超过了镜像区域的范围
            // 但 P[i] 应至少等于 R - i，超过 R 的部分通过中心扩展法进行扩展
            P[i] = MIN(P[j], R - i);
        else
            P[i] = 0;

        // 中心扩展法
        while (t[i + P[i] + 1] == t[i - P[i] - 1])
            ++P[i];

        // 当 i + P[i] 超过回文右边界时，更新 R 和 C
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // 如果 i 处的最长回文子串长度超过了 maxP，更新 maxP, maxI
        if (P[i] > maxP) {
            maxI = i;
            maxP = P[i];
        }
    }

    // 释放预处理字符串的内存
    free(t);
    // 分配新内存给返回的最长回文子串
    t = (char *) malloc(sizeof(char) * (P[maxI] + 1));
    t[P[maxI]] = 0;

    // 复制字符串
    int start = ((maxI - P[maxI]) >> 1);
    int end = (P[maxI] - start);
    for (int i = 0; i < P[maxI]; i++) {
        t[i] = s[start + i];
    }

    free(P);
    return t;
}

int main(int argc, char *argv[])
{
    char * s = "babad";
    char * t = longestPalindrome(s);
    printf("%s\n", t);
    free(t);
    return 0;
}
