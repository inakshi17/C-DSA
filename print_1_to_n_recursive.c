#includde <stdio.h>

void print(int );
int main(){
    int n;
    printf("enter total number : ");
    scanf("%d",&n);
    print(n);
    return 0;
}
void print(int n){
    if(n==0) return;
    else{
        print(n-1);
        printf("%d ",n);
    }
}
