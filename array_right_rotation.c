#include <stdio.h>

int reverse (int a[], int s,int e){
    int temp,i;
    while (s < e) {
        temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        s++;
        e--;
    }
    return 0;
}
int main(){
    int n,i;
    printf("enter the number of element :");
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
    int t;
    printf("\nenter the number of rotation : ");
    scanf("%d",&t);
    t=t%n;
    reverse(a,0,n-1);
    reverse(a,0,t-1);
    reverse(a,t,n-1);

    printf("\nnew array -\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
