#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* gettail(struct ListNode *p, int n, int i) {
    for (int j = 0; j < n - 1 - i; j++) {
        p = p->next;
    }
    return p;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode *temp = head;
    int c = 0;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < c / 2; i++) {
        struct ListNode *tail = gettail(head, c, i);
        if (temp->val != tail->val) {
            return false;
        }
        temp = temp->next;
    }

    return true;
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

    if (isPalindrome(head)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
