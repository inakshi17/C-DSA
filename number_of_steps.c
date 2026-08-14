#include <stdio.h>

int numberOfSteps(int num) {
    int c = 0;
    while (num > 0) {
        if (num % 2 == 0) {
            num = num / 2;
            c++;
        }
        else {
            num = num - 1;
            c++;
        }
    }
    return c;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int steps = numberOfSteps(num);

    printf("Number of steps to reduce %d to zero: %d\n", num, steps);

    return 0;
}
