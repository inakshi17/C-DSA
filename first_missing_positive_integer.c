#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int t = nums[i];
            nums[i] = nums[t - 1];
            nums[t - 1] = t;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) return i + 1;
    }

    return numsSize + 1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = firstMissingPositive(nums, n);
    printf("First missing positive: %d\n", result);

    free(nums);
    return 0;
}
