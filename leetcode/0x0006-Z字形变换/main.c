/* 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。 */

/* 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下： */

/* L   C   I   R */
/* E T O E S I I G */
/* E   D   H   N */

/* 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。 */

/* 请你实现这个将字符串进行指定行数变换的函数： */

/* string convert(string s, int numRows); */

/* 示例 1: */

/* 输入: s = "LEETCODEISHIRING", numRows = 3 */
/* 输出: "LCIRETOESIIGEDHN" */

/* 示例 2: */

/* 输入: s = "LEETCODEISHIRING", numRows = 4 */
/* 输出: "LDREOEIIECIHNTSG" */
/* 解释: */

/* L     D     R */
/* E   O E   I I */
/* E C   I H   N */
/* T     S     G */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/zigzag-conversion */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

char * convert(char * s, int numRows){
    // measure the length of string
    int len = 0;
    while (s[len] != '\0')
        ++len;

    char * ret  = (char *) malloc(sizeof(char) * (len + 1));
    // You have to set memory allocated with 0, otherwise they are initiated with \256
    for (int i = 0; i < len + 1; i++)
        ret[i] = s[i];
    if (numRows == 1)
        return ret;

    int groupLen = (numRows - 1) << 1;
    int index = 0;
    int cursor = 0;
    int sep = 0;
    for (int row = 0; row < numRows; row++) {
        cursor = row;
        sep = row << 1;
        while (cursor < len) {
            ret[index++] = s[cursor];
            sep = groupLen - sep;
            cursor += (row == 0 || row == numRows - 1)? groupLen: sep;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    char * s = "LEETCODEISHIRING";
    char * new = convert(s, 3);
    printf("%s\n", new);
    free(new);
    new = NULL;
    return 0;
}
