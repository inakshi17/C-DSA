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

sl* sortll(sl* head){
    sl* temp=head;
    while(temp!=NULL){
        sl* t=temp;
        int f;
        while(t!=NULL){
            if(temp->data > t->data){
                f=temp->data;
                temp->data=t->data;
                t->data=f;
            }
            t=t->next;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    int n;
    sl* head=NULL;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        head=newnode(head);
    }

    printf("original linked list : ");
    display(head);

    head=sortll(head);
    printf("sorted linked list : ");
    display(head);
    return 0;
} 
