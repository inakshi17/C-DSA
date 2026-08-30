typedef struct node{
    int data;
    struct node *next;
}s;
s* push(s* , s*);
s* pop(s*);
void display(s*);
void peek(s*);
int main(){
    s* top=NULL, *p=NULL;
    int ch;
    do{
        printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            p=(s*)malloc(sizeof(s));
            top=push(p,top);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            display(top);
            break;
            case 4:
            peek(top);
            break;
        }
    }
    while(ch>0 && ch<5);
    return 0;
}
s* push(s* p, s*top){
    int val;
    printf("enter the new element : ");
    scanf("%d", &val);
    p->data=val;
    p->next=top;
    return p;
}
s* pop(s* top){
    if(top==NULL){
        printf("empty !!\n");
        return top;
    }
    s* temp=top;
    top=top->next;
    printf("deleted element : %d", temp->data);
    free(temp);
    return top;
}
void  display(s* top){
    if(top==NULL){
        printf("empty !!\n");
    }
    else {
        s* temp=top;
        printf("stack : ");
        while(temp != NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void peek(s* top){
    if(top==NULL){
        printf("empty !!\n");
    }
    else{
        printf("current position element : %d\n", top->data);
    }
}
