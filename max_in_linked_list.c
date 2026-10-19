#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl* newnode(sl* head) {
    sl *p = (sl*)malloc(sizeof(sl));
    int val;
    printf("enter data : ");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;
    if (head == NULL) {
        return p;
    } else {
        sl* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}

void display(sl* head) {
    if (head == NULL) {
        printf("empty !!!\n");
    } else {
        sl* temp = head;
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void max(sl* head) {
    if (head == NULL) {
        printf("empty!!\n");
        return;
    }
    
    int m = head->data;
    sl* temp = head;
    while (temp != NULL) {
        if (m < temp->data) {
            m = temp->data;
        }
        temp = temp->next;
    }
    printf("max element : %d\n", m);
}

int main() {
    int n;
    sl* head = NULL;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        head = newnode(head);
    }

    printf("linked list : ");
    display(head);

    max(head);

    return 0;
}
