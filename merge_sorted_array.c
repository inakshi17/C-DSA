#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;

    printf("enter size of elements in nums1 (m): ");
    scanf("%d", &m);

    printf("enter size of elements in nums2 (n): ");
    scanf("%d", &n);

    int nums1Size = m + n;
    int *nums1 = (int*)malloc(nums1Size * sizeof(int));
    int *nums2 = (int*)malloc((n + 1) * sizeof(int));

    printf("enter %d sorted elements for nums1: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("enter %d sorted elements for nums2: ", n);
    for (int j = 0; j < n; j++) {
        scanf("%d", &nums2[j]);
    }

    merge(nums1, nums1Size, m, nums2, n, n);

    printf("merged array: ");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    free(nums1);
    free(nums2);

    return 0;
}
