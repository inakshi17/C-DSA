#include <stdio.h>

double myPow(double x, int n) {
    long long N = n;
    
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }
    
    double ans = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            ans *= x;
        }
        x *= x;
        N /= 2;
    }
    
    return ans;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    scanf("%lf", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    double result = myPow(x, n);
    printf("Result: %lf ^ %d = %lf\n", x, n, result);

    return 0;
}
