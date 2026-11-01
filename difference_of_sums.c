#include <stdio.h>

int differenceOfSums(int n, int m) {
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i <= n; i++) {
        if (i % m == 0) {
            s2 = s2 + i;
        } else {
            s1 = s1 + i;
        }
    }
    return s1 - s2;
}

int main() {
    int n = 10;
    int m = 3;
    
    int result = differenceOfSums(n, m);
    printf("Result: %d\n", result);

    return 0;
}
