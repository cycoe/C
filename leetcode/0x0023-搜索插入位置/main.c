/* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 */

/* 你可以假设数组中无重复元素。 */

/* 示例 1: */

/* 输入: [1,3,5,6], 5 */
/* 输出: 2 */

/* 示例 2: */

/* 输入: [1,3,5,6], 2 */
/* 输出: 1 */

/* 示例 3: */

/* 输入: [1,3,5,6], 7 */
/* 输出: 4 */

/* 示例 4: */

/* 输入: [1,3,5,6], 0 */
/* 输出: 0 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/search-insert-position */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

// 二分查找辅助函数
int binarySearch(int * nums, int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (right - left == 1)
            return left + (target > nums[mid]);
        if (target >= nums[mid])
            left = mid;
        else
            right = mid;
    }
    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    return binarySearch(nums, 0, numsSize, target);
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 8};
    printf("Searched insert index is: %d\n", searchInsert(a, sizeof(a)/sizeof(int), 5));
    return 0;
}
