#include <stdio.h>
int main(){
    int i, j, count=0;
    char s[10000];
    scanf("%s",s);
    for(j=0;s[j]!=0;j++){
        if(s[j]>='a' && s[j]<='z'){
            count=1;
            break;
        }
    }
    for(i=j;s[i]!='\0';i++){
        if(s[i]>='A' && s[i]<='Z'){
            count ++;
        }
    }
    printf("%d", count);
    return 0;
}
