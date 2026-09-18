#include <stdio.h>
#include <stdlib.h>

int* getConcatenationAndReverse(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;
    int* ans = (int*)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[numsSize - 1 - i];
    }

    return ans;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* ans = getConcatenationAndReverse(nums, numsSize, &returnSize);

    printf("ans = [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", ans[i], (i == returnSize - 1) ? "" : ", ");
    }
    printf("]\n");

    free(ans);
    return 0;
}
