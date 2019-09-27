/* 编写一个函数来查找字符串数组中的最长公共前缀。 */

/* 如果不存在公共前缀，返回空字符串 ""。 */

/* 示例 1: */

/* 输入: ["flower","flow","flight"] */
/* 输出: "fl" */

/* 示例 2: */

/* 输入: ["dog","racecar","car"] */
/* 输出: "" */
/* 解释: 输入不存在公共前缀。 */

/* 说明: */

/* 所有输入只包含小写字母 a-z 。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/longest-common-prefix */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

char * strCopy(char * s, int start, int end) {
    // 從原字符串 s 拷貝索引 [start, end) 之間的字符到新字符串
    int len = end - start;
    char * ret = (char *) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        ret[i] = s[start + i];
    ret[len] = 0;
    return ret;
}

int strLen(char * s) {
    // 計算字符串長度
    int len = 0;
    while (*s != 0){
        ++len;
        ++s;
    }
    return len;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    // 字符串數組爲空時，直接返回空字符串
    if (strsSize == 0)
        return strCopy("", 0, 0);
    // 字符串數組只有一個元素，返回這個元素的拷貝
    else if (strsSize == 1)
        return strCopy(*strs, 0, strLen(*strs));

    int offset = 0; // 字符串下標偏移
    int equal = 1;  // 字符是否相等

    while (equal) {
        // 字符串數組中相鄰兩個字符串兩兩對比
        for (int i = 0; i < strsSize - 1; i++) {
            equal = (strs[i][offset] == strs[i + 1][offset] && strs[i][offset] != 0);
            // 只要有其中兩個不相等，或等於 0，直接跳出循環
            if (equal == 0)
                break;
        }
        // 如果全部相等，增加偏移量
        if (equal) {
            offset++;
        }
    }
    return strCopy(*strs, 0, offset);
}

int main(int argc, char *argv[])
{
    char * strs[] = {
        "flower",
        "flow",
        "flight"
    };
    printf("%s\n", longestCommonPrefix(strs, 3));
    return 0;
}
