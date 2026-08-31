#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return head;
    }
    else {
        struct ListNode *temp = head;
        struct ListNode *pre = NULL;
        while (temp != NULL) {
            if (temp->val == val && pre == NULL) {
                struct ListNode *p = temp;
                temp = temp->next;
                head = head->next;
                p->next = NULL;
                free(p);
                p = NULL;
            }
            else if (temp->val == val) {
                struct ListNode *p = temp;
                pre->next = p->next;
                temp = temp->next;
                p->next = NULL;
                free(p);
                p = NULL;
            }
            else { 
                pre = temp;
                temp = temp->next;
            }
        }
    }
    return head;
}
struct ListNode* createList(int n) {
    if (n <= 0) return NULL;
    struct ListNode *head = NULL, *tail = NULL;
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;
        if (head == NULL) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
    }
    return head;
}
void printList(struct ListNode *head) {
    printf("List after removal: ");
    struct ListNode *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
void freeList(struct ListNode *head) {
    while (head != NULL) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    int n, target;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct ListNode *head = createList(n);
    if (!head) {
        printf("List is empty.\n");
        return 0;
    }
    printf("Enter value to remove: ");
    scanf("%d", &target);
    head = removeElements(head, target);
    printList(head);
    freeList(head);
    return 0;
}
