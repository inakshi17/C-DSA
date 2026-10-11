#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl;

sl* newnode (sl* head){
    sl*p=(sl*)malloc(sizeof(sl));
    int val;
    printf("enter data : ");
    scanf("%d", &val);
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        return p;
    }
    else{
        sl* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}

void display(sl* head){
    if(head==NULL){
        printf("empty !!!");
    }else{
        sl* temp=head;
        while(temp!= NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

sl* adddata(sl* head, int val){
    sl*p=(sl*)malloc(sizeof(sl));
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        return p;
    }
    else{
        sl* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}

sl* add(sl* head1, sl* head2){
    sl* result=NULL;
    sl* h1=head1;
    sl* h2=head2;
    while(h1 !=NULL && h2!=NULL){
        if(h1->data <= h2->data){
            result=adddata(result, h1->data);
            h1=h1->next;
        }
        else{
            result=adddata(result, h2->data);
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        result=adddata(result,h1->data);
        h1=h1->next;
    }
    while(h2 != NULL){
        result= adddata(result, h2->data);
        h2=h2->next;
    }
    return result;
}

int main(){
    int n, m;
    sl* head1=NULL;
    sl* head2= NULL;

    printf("enter the number of nodes in first ll : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        head1=newnode(head1);
    }

    printf("enter the number of nodes in second ll : ");
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        head2=newnode(head2);
    }

    printf("first ll : ");
    display(head1);
    printf("second ll : ");
    display(head2);

    sl* result=NULL;
    result=add(head1, head2);
    printf("resultant ll : ");
    display(result);

    return 0;
}
