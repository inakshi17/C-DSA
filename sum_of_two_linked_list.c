#include <iostream.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl;

sl* newnode(int val){
    sl* p= (sl*)malloc(sizeof(sl));
    p->data=val;
    p->next=NULL;
    return p;
}

sl* insert(sl* head){
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

sl* sum(sl* head1, sl*head2){
    sl *t1=head1, *t2=head2;
    sl* dummynode=newnode(-1);
    sl* temp=dummynode, *p=NULL;
    int s=0, c=0;
    while(t1 != NULL || t2 != NULL){
        s=c;
        if(t1){s=s + t1->data;}
        if(t2){s=s + t2->data;}
        p=newnode(s%10);
        c=s/10;
        temp->next=p;
        temp=temp->next;
        if(t1){t1=t1->next;}
        if(t2){t2=t2->next;}
    }
    if(c){
        p=newnode(c);
        temp->next=p;
    }
    return dummynode->next;
}

int main(){
    sl* head1=NULL, *head2=NULL;
    int n, m;
    printf("enter the number of nodes for first list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head1=insert(head1);
    }
    printf("enter the number of nodes for second list : ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        head2=insert(head2);
    }
    printf("linked list 1 : ");
    display(head1);
    printf("linked list 2 : ");
    display(head2);
    sl* sumhead= sum(head1, head2); 
    printf("sum linked list : ");
    display(sumhead);
    return 0;
}
