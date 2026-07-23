#include <stdio.h>

void swap(int*, int*);
void swap(int *b, int *c){
    int temp;
    temp=*b;
    *b=*c;
    *c=temp;
}
int main(){
    int n,i;
    printf("enter number of element : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\noriginal array -\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    int high=n-1, mid=0, low=0;
    while(mid<=high){
        if(a[mid]==0){
            swap(&a[mid++],&a[low++]);
        }
        else if(a[mid]==1){
            mid++;
        }
        else if(a[mid]==2){
            swap(&a[mid],&a[high--]);
        }
    }
    printf("\nnew array- \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
