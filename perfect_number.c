#include <stdio.h>

int checkPerfectNumber(int num) {
    if (num <= 1) {
        return 0;
    }

    int s = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            s = s + i;
        }
    }
    if (s == num) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int num;
    printf("enter number: ");
    if (scanf("%d", &num) != 1) {
        return 0;
    }

    if (checkPerfectNumber(num)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
