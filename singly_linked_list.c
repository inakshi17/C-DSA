typedef struct node{
    int data;
    struct node *next;
}sl;
sl* insert(sl*, sl*);
sl* deleteel(sl* , sl*);
void display(sl*);
int main(){
    sl *head=NULL, *p=NULL, *tail=NULL;
    int ch;
    do{
        printf("\n1-insert\n2-delete\n3-display\n4-exit\n");
        printf("enter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            p=(sl*)malloc(sizeof(sl));
            tail=insert(p, tail);
            if(head==NULL){
                head=tail;
            }
            break;
            case 2:
            tail=deleteel(head, tail);
            if(tail==NULL){
                head=NULL;
            }
            break;
            case 3:
            display(head);
            break;
        }
    }
    while(ch>0 && ch<4);
    return 0;
}
sl* insert(sl* p, sl* tail){
    int val;
    printf("enter new value : ");
    scanf("%d", &val);
    p->data=val;
    p->next=NULL;
    if(tail!=NULL){
        tail->next=p;
    }
    return p;
}
sl* deleteel(sl* head,sl*tail){
    if(head==NULL && tail==NULL){
        printf("empty!!");
        return tail;
    }
    if(head==tail){
        free(head);
        return NULL;
    }
    sl* temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    printf("deleted element : %d\n", tail->data);
    temp->next=NULL;
    free(tail);
    return temp;
}
void display(sl* head){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    sl* temp = head;
    while (temp != NULL) { 
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
