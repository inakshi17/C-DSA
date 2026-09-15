#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} sl;

sl* insert(sl* head) {
    int val;
    sl* p = (sl*)malloc(sizeof(sl));
    printf("enter data : ");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;
    p->prev = NULL;

    if (head == NULL) {
        head = p;
    } else {
        sl* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
    return head;
}

void display(sl* head) {
    if (head == NULL) {
        printf("empty list !!\n");
        return;
    }

    sl* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
        if (temp == head) {
            printf("head\n");
            return;
        }
    }
    printf("NULL\n");
}

sl* lltcl(sl* head) {
    if (head == NULL) {
        printf("empty list !!\n");
        return head;
    }
    sl* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
    return head;
}

sl* cltll(sl* head) {
    if (head == NULL) {
        printf("empty list !!\n");
        return head;
    }
    sl* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = NULL;
    head->prev = NULL;
    return head;
}

int main() {
    sl* head = NULL;
    int n;
    printf("enter the number of nodes for first list : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        head = insert(head);
    }
    printf("original linked list  : ");
    display(head);
    printf("circular linked list : ");
    head = lltcl(head);
    display(head);
    printf("single linked list : ");
    head = cltll(head);
    display(head);
    return 0;
}
