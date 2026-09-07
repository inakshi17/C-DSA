#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl;

sl* newnode(sl* head){
    int val;
    sl*p=(sl*)malloc(sizeof(sl));
    printf("enter data : ");
    scanf("%d", &val);
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        sl*temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}

void display(sl*head){
    if(head==NULL){
        printf("empty list !!");
    }
    else{
        sl* temp=head;
        while(temp != NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void midpoint(sl* head, int n){
    if(head==NULL){
        printf("empty list !!");
    }
    else if(head->next == NULL){
        printf("mid data of linked list : %d",head->data);
    }
    else{
        sl* temp=head;
        int mid=n/2;
        while((mid-1) !=0){
            temp=temp->next;
            mid--;
        }
        if(n%2==0){
            printf("mid data of linked list : %d",temp->data);
        }
        else{
            printf("mid data of linked list : %d", temp->next->data);
        }
    }
}

int main(){
    sl* head=NULL;
    int n;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=newnode(head);
    }
    printf("original linked list : ");
    display(head);
    midpoint(head, n);
    return 0;
}
