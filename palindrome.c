#include <stdio.h>

int check(int a[], int n, int start , int end ){
    if(start>=end){
        return 1;
    }
    if(a[start]!=a[end]){
        return 0;
    }
    return check(a, n, start+1, end-1);
}
int main(){
    int n;
    printf("enter the number of element : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    int start =0, end=n-1, result;
    result = check(a, n, start, end);
    if(result==1){
        printf("\nnumber is palindrome !! \n");
    }
    else { printf("\nnumber is not a palindrome !!\n");}
    return 0;
}
