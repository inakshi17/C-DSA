#include <stdio.h>
#include <stdbool.h>

bool isHappy(int n) {
    int d, s = 0;
    if (n == 1) {
        return true;
    }
    while (n != 1 && n != 4) {
        s = 0;
        while (n > 0) {
            d = n % 10;
            s = s + d * d;
            n = n / 10;
        }
        n = s;
        if (s == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (isHappy(number)) {
        printf("%d is a Happy number.\n", number);
    } else {
        printf("%d is NOT a Happy number.\n", number);
    }

    return 0;
}
