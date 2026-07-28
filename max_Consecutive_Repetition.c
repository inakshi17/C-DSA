#include <stdio.h>

int count(int a[], int n) {
    if (n <= 0) return -1;
    int c = 0, ele = a[0], s = 0, num = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] != ele) {
            ele = a[i];
            c = 0;
        }
        c++;
        if (c > s) {
            s = c;
            num = ele;
        }
    }

    return num;
}
int main(){
    int n;
    printf("enter the number of element : ");
    scanf("%d", &n );
    int a[n];
    for(int i=0;i<n;i++){
        printf("element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    int result;
    result = count(a,n);
    printf("result : %d", result);
    return 0;
}
