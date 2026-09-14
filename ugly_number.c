#include <stdio.h>
#include <stdbool.h>

bool isUgly(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}
int main() {
    int n;
    printf("enter number: ");
    scanf("%d", &n);
    if (isUgly(n)) {
        printf("result: true\n");
    } 
    else {
        printf("result: false\n");
    }
    return 0;
}
