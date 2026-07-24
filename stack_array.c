#include <stdio.h>
# define MAX 10

int push(int [], int);
int pop(int [],int);
void peek(int [], int);
void display(int [], int);

int main(){
    int a[MAX], top=-1 , ch;
    do{
        printf("\n1-push\n2-pop\n3-peek\n4-display\n5-exit");
        printf("\nenter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            top=push(a, top);
            break;
            case 2:
            top=pop(a, top);
            break;
            case 3:
            peek(a, top);
            break;
            case 4:
            display(a, top);
            break;
        }
    }
    while(ch>=1 && ch<=4);
    return 0;
}

int push(int a[], int top){
    int z;
    if(top==MAX-1){
        printf("stack is full");
    }
    else{
        printf("enter new element : ");
        scanf("%d",&z);
        a[++top]=z;
    }
    return top;
}

int pop(int a[], int top){
    int z;
    if(top==-1){
        printf("stack is empty");
    }
    else{
        z=a[top--];
        printf("deleted element : %d",z);
    }
    return top;
}

void peek(int a[], int top){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("currently : %d",a[top]);
    }
}

void display(int a[], int top){
    int i=0;
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("\n");
        while(i<top+1){
            printf("%d ",a[i++]);
        }
    }
    printf("\n");
}
