#include <stdio.h>

int main(){
    int n;
    printf("enter the number of candles : ");
    scanf("%d", &n);
    int a[n];
    int max=a[0], count=0;
    for(int i=0;i<n;i++){
        printf("candle %d : ",i+1);
        scanf("%d", &a[i]);
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==max){
            count++;
        }
    }
    printf("%d candles blow out !!");
    return 0;
}
