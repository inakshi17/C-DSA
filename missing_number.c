#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int n;
    printf("enter size: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Missing Number: %d\n", missingNumber(nums, n));

    free(nums);
    return 0;
}
