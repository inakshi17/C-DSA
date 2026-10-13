#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} cll;

cll* newnode(cll* head) {
    int val;
    cll* p = (cll*)malloc(sizeof(cll));
    printf("enter element : ");
    scanf("%d", &val);
    p->data = val;

    if (head == NULL) {
        p->next = p;
        return p;
    }

    cll* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = p;
    p->next = head;
    
    return head;
}

void display(cll* head) {
    if (head == NULL) {
        printf("empty !!!\n");
        return;
    }
    cll* temp = head;
    while (temp->next != head) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->HEAD\n", temp->data);
}

cll* add(cll* head1, cll* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    cll* tail1 = head1;
    while (tail1->next != head1) {
        tail1 = tail1->next;
    }
    
    cll* tail2 = head2;
    while (tail2->next != head2) {
        tail2 = tail2->next;
    }
    
    tail1->next = head2;
    tail2->next = head1;

    return head1;
}

int main() {
    int n, m;
    cll* h1 = NULL;
    cll* h2 = NULL;
    
    printf("enter number of first cll node : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        h1 = newnode(h1);
    }
    
    printf("enter number of second cll node : ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        h2 = newnode(h2);
    }

    printf("first cll : ");
    display(h1);
    printf("second cll : ");
    display(h2);

    cll* result = add(h1, h2);
    printf("new cll : ");
    display(result);

    return 0;
}
