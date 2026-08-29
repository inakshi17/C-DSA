#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

Node* deleteDuplicates(Node* head) {
    if (head == NULL) { return head; }
    Node* temp = head;
    Node* p = NULL;
    while (temp->next != NULL) {
        p = temp->next;
        if (temp->next->val == temp->val) {
            temp->next = p->next;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter sorted values: ");
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = deleteDuplicates(head);

    printf("List after removing duplicates: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("\n");

    return 0;
}
