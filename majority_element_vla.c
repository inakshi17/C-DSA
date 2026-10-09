#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int max = 0;
    int maxele = nums[0];
    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        c = 0;
        int curr = nums[i];
        if (curr != -1000000001) {
            for (int j = i; j < numsSize; j++) {
                if (curr == nums[j]) {
                    c++;
                    nums[j] = -1000000001;
                }
            }
        }
        if (c > max) {
            max = c;
            maxele = curr;
        }
    }
    return maxele;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int nums[n]; 

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = majorityElement(nums, n);
    printf("Majority Element: %d\n", result);

    return 0;
}
