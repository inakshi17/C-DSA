#include <stdio.h>

int mySqrt(int x) {
    long r = x;
    while (r * r > x) {
        r = (r + x / r) / 2;
    }
    return (int)r;
}
int main() {
    int x;
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    int result = mySqrt(x);
    printf("The square root of %d is: %d\n", x, result);
    return 0;
}
