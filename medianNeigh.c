#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}
int partition(int* nums, int left, int right, int pivot_index) {
    int pivot = nums[pivot_index];
    swap(&nums[pivot_index], &nums[right]);
    int stored_index = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(&nums[i], &nums[stored_index]);
            stored_index++;
        }
    }
    swap(&nums[right], &nums[stored_index]);
    return stored_index;
}
int findMedian(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    srand(time(NULL));
    while (1) {
        int pivot_index = left + rand() % (right - left + 1);
        int new_pivot_index = partition(nums, left, right, pivot_index);
        if (new_pivot_index == numsSize - k) {
            return new_pivot_index;
        } else if (new_pivot_index > numsSize - k) {
            right = new_pivot_index - 1;
        } else {
            left = new_pivot_index + 1;
        }
    }
}
int main() {
    int nums[] = {156,23,48,73};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = (n/2)+1;
    int result = findMedian(nums, sizeof(nums) / sizeof(nums[0]), k);
    printf("The Median is: %d\n", nums[result]);
    printf("The neighbours are: %d and %d\n", nums[result-1],nums[result+1]);
    return 0;
}
