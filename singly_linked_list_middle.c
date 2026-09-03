#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    int c = 0;
    struct ListNode *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    int k = 0;
    temp = head;
    c = (c / 2) + 1;
    while (temp != NULL) {
        k++;
        if (k == c) {
            return temp;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    int n, val;
    struct ListNode *head = NULL, *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct ListNode *mid = middleNode(head);
    if (mid != NULL) {
        printf("%d", mid->val);
    }

    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
