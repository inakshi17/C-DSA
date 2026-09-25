#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, target;
    printf("enter size: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("enter target: ");
    scanf("%d", &target);

    printf("Index: %d\n", search(nums, n, target));

    free(nums);
    return 0;
}
