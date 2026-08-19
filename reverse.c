#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long long int d, s = 0;
    while (x != 0) {
        d = x % 10;
        s = s * 10 + d;
        x = x / 10;
    }
    if (s > INT_MAX || s < INT_MIN) {
        return 0;
    }
    return (int)s;
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Reversed integer: %d\n", reverse(num));

    return 0;
}
