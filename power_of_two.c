#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    long long m = 1;
    long long temp = n;
    while (true) {
        temp = n;
        if (temp == m) {
            return true;
        }
        else if (temp < m) {
            return false;
        }
        m = 2 * m;
    }
}

int main() {
    int n;
    printf("enter number: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (isPowerOfTwo(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
