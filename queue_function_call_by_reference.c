#include <stdio.h>
#define max 10
void enqueue(int [], int*, int *);
void dequeue(int [], int *, int*);
void display(int [], int, int);
void peek(int [], int);

int main(){
    int f=-1, r=-1, a[max], ch;
    do{
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-peek\n5-exit");
        printf("\nenter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            enqueue(a, &f, &r);
            break;
            case 2:
            dequeue(a, &f, &r);
            break;
            case 3:
            display(a, f, r);
            break;
            case 4:
            peek(a,f);
            break;
        }
    } while(ch>0 && ch<=4);
    return 0;
}

void enqueue(int a[], int *f, int *r){
    if (*r==max-1){
        printf("queue is full !!\n");
    }
    else {
        int x;
        printf("enter the new value : ");
        scanf("%d", &x);
        a[++(*r)]=x;
        if((*r)>-1 && (*f)==-1){
            *f=0;
        }
    }
}
void dequeue(int a[], int *f, int *r){
    if((*f)==-1){
        printf("queue is empty !!\n");
    }
    else{
        printf("deleted element : %d\n", a[(*f)]);
        if((*f)==(*r)){
            *f=-1;
            *r=-1;
        }
        else{ (*f)++;}
    }
}
void display(int a[], int f, int r){
    if(f==-1){
        printf("queue is empty !!\n");
    }
    else{
        printf(" current queue : ");
        while(f<=r){
            printf("%d ", a[f++]);
        }
    }
}
void peek(int a[], int f){
    if(f==-1){
        printf("queue is empty !!\n");
    }
    else {
        printf("current value : %d", a[f]);
    }
}
