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
    int * left = &height[0];               // 待求解区域左边界
    int * right = &height[heightSize - 1]; // 待求解区域右边界
    int * cl = left + 1;          // 左指针
    int * cr = right - 1;         // 右指针
    int ret = 0;                // 返回值

    while (cl <= right && cr >= left) {
        // 如果右边界较矮则移动右指针
        if (*left > *right) {
            // 当右指针移动到比右边界高的位置时
            // 认为右指针与右边界之间形成了一个坑
            if (*cr >= *right) {
                // 水面高度等于右指针和右边界中的较小值
                // 水面宽度等于 right - cr - 1
                ret += *right * (right - cr - 1);
                // 更新右边界
                right = cr;
            }
            else
                // 减去坑底的高度
                ret -= *cr;
            // 移动右指针
            --cr;
        }
        // 如果左边界较矮则移动左指针
        else {
            if (*cl >= *left) {
                ret += *left * (cl - left - 1);
                left = cl;
            }
            else
                ret -= *cl;
            ++cl;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("water volume is: %d\n", trap(height, sizeof(height) / sizeof(int)));
    return 0;
}
