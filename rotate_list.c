#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    k = k % length;
    if (k == 0) return head;
    tail->next = head;
    int stepsToNewTail = length - k;
    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr) {
        printf("%d%s", curr->val, curr->next ? " -> " : "");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("enter elements: ");
    int val;
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* curr = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        curr->next = createNode(val);
        curr = curr->next;
    }

    printf("enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated List: ");
    printList(head);

    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
