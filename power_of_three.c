#include <stdio.h>

int isPowerOfThree(int n) {
    if (n <= 0) {
        return 0;
    }
    long long m = 1;
    while (m <= n) {
        if (m == n) {
            return 1;
        }
        m = m * 3;
    }
    return 0;
}

int main() {
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    if (isPowerOfThree(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
