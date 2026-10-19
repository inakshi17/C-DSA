#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} dl;

dl* newnode(dl* head) {
    int val;
    printf("enter data : ");
    scanf("%d", &val);
    dl* p = (dl*)malloc(sizeof(dl));
    p->data = val;
    p->next = NULL;

    if (head == NULL) {
        p->prev = NULL;
        return p;
    } else {
        dl* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp; 
    }
    return head;
}

void display(dl* head) {
    if (head == NULL) {
        printf("empty !!\n");
    } else {
        dl* temp = head;
        printf("NULL<->");
        while (temp != NULL) {
            printf("%d<->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void check(dl* head) {
    if (head == NULL) {
        printf("empty !!!\n");
        return;
    }
    
    dl* start = head;
    dl* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    while (start != tail && start->prev != tail) {
        if (start->data != tail->data) {
            printf("false\n");
            return;
        }
        start = start->next;
        tail = tail->prev;
    }
    printf("true\n");
}

int main() {
    int n;
    dl* head = NULL;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        head = newnode(head);
    }

    printf("double linked list : ");
    display(head);

    printf("is palindrome : ");
    check(head);

    return 0;
}
