#include <stdio.h>
#include <stdlib.h>
int findDuplicate(int* nums, int numsSize) {
    int low = 1;
    int high = numsSize - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] <= mid) {
                count++;
            }
        }
        if (count > mid) {
            high = mid; 
        } else {
            low = mid + 1; 
        }
    }
    return low;
}
int main() {
    int numsSize;
    printf("Enter total number of elements (N + 1): ");
    if (scanf("%d", &numsSize) != 1 || numsSize <= 1) {
        printf("Invalid input size.\n");
        return 1;
    }
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter %d integers (values should be between 1 and %d): \n", numsSize, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    int duplicate = findDuplicate(nums, numsSize);
    printf("The duplicate number is: %d\n", duplicate);
    free(nums);
    return 0;
}
