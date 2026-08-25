#include <stdio.h>

int missingMultiple(int* nums, int numsSize, int k) {
    for (int m = 1; ; m++) {
        int target = k * m;
        int i;
        
        for (i = 0; i < numsSize; i++) {
            if (nums[i] == target) {
                break;
            }
        }

        if (i == numsSize) {
            return target;
        }
    }
}

int main() {
    int numsSize, k;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &numsSize) != 1 || numsSize <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int nums[numsSize];

    printf("Enter %d space-separated elements: ", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = missingMultiple(nums, numsSize, k);
    printf("Smallest missing multiple: %d\n", result);

    return 0;
}
