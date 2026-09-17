#include <stdio.h>

int count(int n) {
    if (n == 0) return 1;
    int s = 0;
    while (n != 0) {
        n = n / 10;
        s++;
    }
    return s;
}
int findNumbers(int* nums, int numsSize) {
    int c = 0, n = 0;
    for (int i = 0; i < numsSize; i++) {
        c = count(nums[i]);
        if (c % 2 == 0) {
            n++;
        }
    }
    return n;
}
