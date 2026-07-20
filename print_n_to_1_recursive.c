#include <stdio.h>

void print(int);
int main(){
    int n;
    printf("enter total number : ");
    scanf("%d",&n);
    print(n);
    return 0;
}
void print(int n){
    if(n==0) return;
    else {
        printf("%d ",n);
        print(n-1);
    }
}
