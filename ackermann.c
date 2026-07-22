#include <stdio.h>

int ack(int, int);
int main(){
    int n,m,z=0;
    printf("enter the value of m : ");
    scanf("%d",&m);
    printf("enter the value of n : ");
    scanf("%d",&n);
    z=ack(m,n);
    printf("result - %d",z);
    return 0;
}
int ack(int m, int n){
    if(m==0){
        return n+1;
    }
    else if(m>0 && n==0){
        ack(m-1,1);
    }
    else if (m>0 && n>0){
        ack(m-1, ack(m, n-1));
    }
}
