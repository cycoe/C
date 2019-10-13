#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void merge(int * nums, int * tmp, int leftStart, int rightStart, int rightEnd, int reverse) {
    int cur = leftStart;
    int leftEnd = rightStart - 1;
    int numsSize = rightEnd - leftStart + 1;
    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if ((nums[leftStart] < nums[rightStart]) ^ reverse)
            tmp[cur++] = nums[leftStart++];
        else
            tmp[cur++] = nums[rightStart++];
    }
    while (leftStart <= leftEnd)
        tmp[cur++] = nums[leftStart++];
    while (rightStart <= rightEnd)
        tmp[cur++] = nums[rightStart++];
    for (int i = 0; i < numsSize; i++, rightEnd--) {
        nums[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(int * nums, int * tmp, int left, int right, int reverse) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, tmp, left, mid, reverse);
        mergeSort(nums, tmp, mid + 1, right, reverse);
        merge(nums, tmp, left, mid + 1, right, reverse);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {2,3,4,1,7,2,3,4,8,2};
    int len = sizeof(arr) / sizeof(int);
    int * tmp = (int *) malloc(sizeof(arr));
    mergeSort(arr, tmp, 0, len - 1, 0);
    for (int i = 0; i < len; i++)
        printf("%d: %d\n", i, arr[i]);
    return 0;
}
