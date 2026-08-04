#include <stdio.h>
double findMedianSortedArrays(int* a, int n, int* b, int m) {
    int c[n + m];
    int j = 0, k = 0, i = 0;
    while (j < n && k < m) {
        if (a[j] < b[k]) {
            c[i++] = a[j++];
        } else {
            c[i++] = b[k++];
        }
    }
    while (j < n) {
        c[i++] = a[j++];
    }
    while (k < m) {
        c[i++] = b[k++];
    }
    float med;
    int total = n + m;
    if (total % 2 == 0) {
        float s = c[total / 2] + c[(total / 2) - 1];
        med = s / 2.0f;
    } else {
        med = c[total / 2];
    }

    return med;
}
int main() {
    int n, m;
    printf("Enter the size of first sorted array (n): ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d sorted elements for first array: ", n);
    for (int i = 0; i < n; i++) {
        printf("element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter the size of second sorted array (m): ");
    scanf("%d", &m);
    int b[m];
    printf("Enter %d sorted elements for second array: ", m);
    for (int i = 0; i < m; i++) {
        printf("element %d : ", i+1);
        scanf("%d", &b[i]);
    }
    double median = findMedianSortedArrays(a, n, b, m);
    printf("The median of the two sorted arrays is: %.2f\n", median);
    return 0;
}
