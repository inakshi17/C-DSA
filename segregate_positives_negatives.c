#include <stdio.h>
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
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
    printf("\noriginal array -\n");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    int start=0, end=n-1;
    while(start<end){
        if(a[start] < 0 && a[end] > 0) {
            swap(&a[start], &a[end]);
            start++;
            end--;
        } else {
            if(a[start] >= 0) start++;
            if(a[end] <= 0) end--;
        }
    }
    printf("\nnew array -\n");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}
