#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void insertNode(struct ListNode** headRef, struct ListNode** tailRef, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        (*tailRef)->next = newNode;
    }
    *tailRef = newNode;
}

void printList(const char* label, struct ListNode* head) {
    printf("%s: ", label);
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* temp = &dummy;

    struct ListNode* head1 = list1;
    struct ListNode* head2 = list2;

    while (head1 != NULL && head2 != NULL) {
        if (head1->val <= head2->val) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    return dummy.next;
}

int main() {
    struct ListNode *head1 = NULL, *tail1 = NULL;
    struct ListNode *head2 = NULL, *tail2 = NULL;
    int n1, n2, val;

    printf("enter size of list 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("enter list 1 node %d: ", i + 1);
        scanf("%d", &val);
        insertNode(&head1, &tail1, val);
    }

    printf("enter size of list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("enter list 2 node %d: ", i + 1);
        scanf("%d", &val);
        insertNode(&head2, &tail2, val);
    }

    struct ListNode* merged = mergeTwoLists(head1, head2);

    printList("merged list", merged);

    return 0;
}
