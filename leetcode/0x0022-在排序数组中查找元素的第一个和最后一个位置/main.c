/* 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 */

/* 你的算法时间复杂度必须是 O(log n) 级别。 */

/* 如果数组中不存在目标值，返回 [-1, -1]。 */

/* 示例 1: */

/* 输入: nums = [5,7,7,8,8,10], target = 8 */
/* 输出: [3,4] */

/* 示例 2: */

/* 输入: nums = [5,7,7,8,8,10], target = 6 */
/* 输出: [-1,-1] */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void searchRangeHelper(int *nums, int *ret, int target, int left, int right)
{
    if (left > right)
        return;

    int mid = (left + right) >> 1;
    if (target == nums[mid]) {
        if (ret[0] == -1 || mid < ret[0])
            ret[0] = mid;
        if (mid > ret[1])
            ret[1] = mid;
        searchRangeHelper(nums, ret, target, left, mid - 1);
        searchRangeHelper(nums, ret, target, mid + 1, right);
    }
    else if (target < nums[mid])
        searchRangeHelper(nums, ret, target, left, mid - 1);
    else
        searchRangeHelper(nums, ret, target, mid + 1, right);
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int *) malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;
    searchRangeHelper(nums, ret, target, 0, numsSize - 1);
    return ret;
}

int main(int argc, char *argv[])
{
    int nums[] = {5, 7, 7, 8 ,8 ,10};
    int returnSize;
    int *ret = searchRange(nums, sizeof(nums) / sizeof(int), 8, &returnSize);
    printf("[%d, %d]\n", ret[0], ret[1]);
    free(ret);
    return 0;
}
