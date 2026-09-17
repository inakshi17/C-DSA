#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}sl;

sl* insertatend(sl *head,sl *p){
    if(head==NULL){
        return p;
    }
    else{
        sl* temp=head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=p;
        return head;
    }
}

sl* insert(sl* head, int val){
    sl* p=(sl*)malloc(sizeof(sl));
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        return p;
    }
    else{
        head=insertatend(head, p);
        return head;
    }
}

void display(sl* head){
    if(head==NULL){
        printf("empty list !!\n");
    }
    else{
        sl* temp=head;
        while(temp != NULL){
            printf("%d->", temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

sl* sortlist(sl* head){
    if(head==NULL){
        printf("empty list !!\n");
        return head;
    }
    else{
        sl* head0=NULL, *head1=NULL, *head2=NULL, *temp=head;
        while(temp!= NULL){
            if(temp->data==0){
                head0=insert(head0, 0);
            }
            else if(temp->data==1){
                head1=insert(head1, 1);
            }
            else{
                head2=insert(head2, 2);
            }
            temp=temp->next;
        }
        head0=insertatend(head0,head1);
        head0=insertatend(head0, head2);
        return head0;
    }
}

int main(){
    sl* head=NULL;
    int n;
    printf("enter the number of nodes : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x;
        printf("%d node : ", i+1);
        scanf("%d", &x);
        head=insert(head, x);
    }
    printf("original list : ");
    display(head);

    printf("new list : ");
    head=sortlist(head);
    display(head);

    return 0;
}
