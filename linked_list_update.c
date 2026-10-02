#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl;

sl* insertval( sl* head, int val ){
    sl*temp=head;
    sl* p=(sl*)malloc(sizeof(sl));
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        return p;
    }
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=p;
    return head;
}

void display(sl* head){
    sl* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

sl* updatenode(sl* head, int c){
    sl* temp=head;
    int u, f=0;
    printf("enter updated value : ");
    scanf("%d",&u);
    while(temp!=NULL){
        if(temp->data==c){
            f=1;
            temp->data=u;
        }
        temp=temp->next;
    }
    if(f==0){
        printf("value not found !!!");
    }
    else{
        printf("updated list - ");
        display(head);
    }
    return head;
}

int main(){
    sl* head=NULL;
    int n, val;
    printf("enter the number of nodes : ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        printf("element %d : ",i);
        scanf("%d",&val);
        head=insertval(head, val);
    }
    printf("original list - ");
    display(head);

    int c;
    printf("the value you want to change : ");
    scanf("%d", &c);
    head=updatenode(head, c);
    
    return 0;
}
