#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* result = NULL;
    struct ListNode* temp = head->next;
    struct ListNode* headr = NULL;
    int s = 0;
    while (temp != NULL) {
        s = 0;
        while (temp->val != 0) {
            s = s + temp->val;
            temp = temp->next;
        }
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = s;
        p->next = NULL;
        if (result == NULL) {
            result = p;
            headr = result;
        } else {
            result->next = p;
            result = result->next;
        }
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    return headr;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("enter values (must start and end with 0): ");
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* current = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        current->next = createNode(val);
        current = current->next;
    }

    printf("Original list: ");
    printList(head);

    struct ListNode* res = mergeNodes(head);

    printf("Merged list: ");
    printList(res);

    while (res != NULL) {
        struct ListNode* temp = res;
        res = res->next;
        free(temp);
    }

    return 0;
}
