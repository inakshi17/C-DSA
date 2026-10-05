#include <stdio.h>

int isPowerOfFour(int n) {
    long long m = 1;
    while (m <= n) {
        if (m == n) {
            return 1;
        }
        m = m * 4;
    }
    return 0;
}

int main() {
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    if (isPowerOfFour(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
