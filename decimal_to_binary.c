#include <stdio.h>

int convert(int n, int s, int t){
    int r ;
    if(n<=0){
        return s;
    }
    else{
        r=n%2;
        s=s+r*t;
        t=t*10;
        return convert(n/2,s,t);
    }
}
int main(){
    int n, result;
    printf("enter your number : ");
    scanf("%d",&n);
    result= convert(n,0,1);
    printf("result = %d",result);
    return 0;
}
