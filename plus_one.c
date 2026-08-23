#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* a, int n, int* b) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 9) {
            a[i] = 0;
        } else {
            a[i] += 1;
            *b = n;
            return a;
        }
    }
    int *res = (int*)calloc(n + 1, sizeof(int));
    res[0] = 1;
    *b = n + 1;
    return res;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int returnSize;
    int* result = plusOne(arr, n, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], (i < returnSize - 1) ? ", " : "");
    }
    printf("]\n");

    if (result != arr) free(arr);
    free(result);

    return 0;
}
