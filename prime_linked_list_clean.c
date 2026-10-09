#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl* newnode(sl* head) {
    sl* p = (sl*)malloc(sizeof(sl));
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

int checkprime(int x) {
    if (x <= 1) return 0;
    int c = 0;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            c++;
        }
    }
    if (c == 2) {
        return 1;
    } else {
        return 0;
    }
}

sl* prime(sl* head) {
    sl* result = NULL;
    sl* tail = NULL;
    sl* temp = head;

    while (temp != NULL) {
        if (checkprime(temp->data)) {
            sl* p = (sl*)malloc(sizeof(sl));
            p->data = temp->data;
            p->next = NULL;

            if (result == NULL) {
                result = p;
                tail = p;
            } else {
                tail->next = p;
                tail = tail->next;
            }
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    int n;
    sl* head = NULL;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        head = newnode(head);
    }
    printf("original linked list : ");
    display(head);

    sl* prime_head = prime(head);
    printf("prime number linked list : ");
    display(prime_head);

    return 0;
}
