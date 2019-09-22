/* 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 */

/* 说明：你不能倾斜容器，且 n 的值至少为 2。 */

/* 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 */

/* 示例: */

/* 输入: [1,8,6,2,5,4,8,3,7] */
/* 输出: 49 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/container-with-most-water */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <time.h>

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int pivot = 0;
    int maxV = 0;
    int V = 0;

    while (right > left) {
        pivot = (height[left] > height[right])? height[right]: height[left];
        V = pivot * (right - left);
        maxV = V > maxV? V: maxV;
        if (height[left] > height[right])
            while (height[--right] < pivot);
        else
            while (height[++left] < pivot);
    }

    return maxV;
}

int main(int argc, char *argv[])
{
    int a[] = {1,8,6,2,5,4,8,3,7,10,12,18,20,1,20,1,24,15,2,5,6,2,3,6,8,9,6,5,4,3,1,5,7,10};
    clock_t start, end;
    start = clock();
    printf("%d\n", maxArea(a, sizeof(a) / sizeof(int)));
    end = clock();
    printf("%u\n", start - end);
    return 0;
}
