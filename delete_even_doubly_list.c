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

dl* deleteevennode(dl* head) {
    dl* temp = head;
    while (temp != NULL) {
        dl* nextnode = temp->next;
        
        if (temp->data % 2 == 0) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                free(temp);
            }
            else if (temp->next == NULL) {
                temp->prev->next = NULL;
                free(temp);
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
        }
        temp = nextnode;
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

    printf("new linked list : ");
    head = deleteevennode(head);
    display(head);

    return 0;
}
