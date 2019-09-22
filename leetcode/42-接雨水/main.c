/* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 */

/* 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。 */

/* 示例: */

/* 输入: [0,1,0,2,1,0,1,3,2,1,2,1] */
/* 输出: 6 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/trapping-rain-water */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

int trap(int* height, int heightSize){
    int left = 0;
    int right = 0;
    int up = 0;
    int sum = 0;
    int block = 0;
    while (right < heightSize - 1) {
        right++;
        if (height[right] > height[right - 1] && up == 0) {
            up = 1;
        }
        if (height[right] < height[right - 1] && up == 1) {
            up = 0;
            int povit = height[left] > height[right - 1]? height[right - 1]: height[left];
            for (int i = left + 1; i < right - 1; i++) {
                sum += povit - height[i];
            }
            left = right - 1;
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", trap(height, sizeof(height) / sizeof(int)));
    return 0;
}
