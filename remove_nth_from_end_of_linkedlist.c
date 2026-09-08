#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl* newnode(sl* head) {
    int val;
    sl* p = (sl*)malloc(sizeof(sl));
    printf("enter data : ");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;

    if (head == NULL) {
        head = p;
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
        printf("empty list !!\n");
    } else {
        sl* temp = head;
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

sl* removeNthFromEnd(sl* head, int n) {
    if (head == NULL) return NULL;

    sl* temp = head;
    int c = 0;
    while (temp != NULL) {
        temp = temp->next;
        c++;
    }

    if (n == c) {
        sl* toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }

    temp = head;
    for (int i = 1; i < c - n; i++) {
        temp = temp->next;
    }

    sl* p = temp->next;
    temp->next = p->next;
    free(p);

    return head;
}

int main() {
    sl* head = NULL;
    int n, k;

    printf("enter the number of nodes : ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        head = newnode(head);
    }

    printf("original linked list : ");
    display(head);

    printf("enter n (node from end to delete): ");
    scanf("%d", &k);

    head = removeNthFromEnd(head, k);

    printf("updated linked list : ");
    display(head);

    return 0;
}
