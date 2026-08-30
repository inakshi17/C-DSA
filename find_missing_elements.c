#include <stdio.h>
#include <stdlib.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) { 
        *returnSize = 0;
        return NULL; 
    }
    
    int min = nums[0], max = nums[0], k = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    int totalRange = max - min + 1;
    int maxPossibleMissing = totalRange - numsSize;
    int* result = (int*)malloc(maxPossibleMissing * sizeof(int));

    for (int target = min; target <= max; target++) {
        int found = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == target) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = target;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Missing elements: []\n");
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* missing = findMissingElements(nums, n, &returnSize);

    printf("Missing elements: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", missing[i], (i == returnSize - 1) ? "" : ", ");
    }
    printf("]\n");

    free(nums);
    free(missing);
    return 0;
}
