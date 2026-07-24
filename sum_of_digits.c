#include <iostream>
using namespace std;

int main(){
    int s, n;
    printf("enter your number : ");
    scanf("%d",&n);
    s=n%9;
    if(s==0 && n!=0){
        s=9;
    }
    printf("sum : %d",s);
    return 0;
}
