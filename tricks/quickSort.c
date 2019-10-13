#include <stdio.h>

int getIndex(int * nums, int low, int high, int reverse) {
    int tmp = nums[low];
    while (low < high) {
        while (low < high && (nums[high] > tmp ^ reverse || nums[high] == tmp)) high--;
        nums[low] = nums[high];
        while (low < high && (nums[low] < tmp ^ reverse || nums[low] == tmp)) low++;
        nums[high] = nums[low];
    }
    nums[low] = tmp;
    return low;
}

void quickSort(int * nums, int low, int high, int reverse) {
    if (low < high) {
        int index = getIndex(nums, low, high, reverse);
        quickSort(nums, 0, index - 1, reverse);
        quickSort(nums, index + 1, high, reverse);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {2,3,4,1,7,2,3,4,8,2};
    int len = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, len - 1, 1);
    for (int i = 0; i < len; i++)
        printf("%d: %d\n", i, arr[i]);
    return 0;
}
