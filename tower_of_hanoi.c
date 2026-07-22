#include <stdio.h>

void tower(int, char, char, char);
int main(){
    int n;
    printf("enter number of disk : ");
    scanf("%d",&n);
    char A='A', B='B', C='C';
    tower(n,A,B,C);
    return 0;
}
void tower (int n, char A, char B, char C){
    if(n==1){
        printf("%c -> %c\n",A,C);
        return;
    }
    tower(n-1,A,C,B);
    printf("%c -> %c\n",A,C);
    tower(n-1,B,A,C);
}
