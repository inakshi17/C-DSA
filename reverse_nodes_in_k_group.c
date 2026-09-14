#include <stdio.h>
#include <stdlib.h>

typedef struct sl {
    int val;
    struct sl *next;
} sl;

void insertNode(sl** headRef, sl** tailRef, int val) {
    sl* newNode = (sl*)malloc(sizeof(sl));
    newNode->val = val;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        (*tailRef)->next = newNode;
    }
    *tailRef = newNode;
}

void printList(const char* label, sl* head) {
    printf("%s: ", label);
    sl* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

sl* reverseKGroup(sl* head, int k) {
    if (head == NULL || k == 1) return head;

    sl dummy;
    dummy.next = head;
    sl *pre = &dummy;
    sl *temp = head;
    sl *groupStart = head;
    int c = 0;

    while (temp != NULL) {
        c++;
        sl *nextTemp = temp->next; 
        if (c % k == 0) {
            sl *first = groupStart;
            sl *last = temp;
            sl *p = last->next;
            sl *next = first;

            while (first != last) {
                next = first->next;
                first->next = p;
                p = first;
                first = next;
            }
            last->next = p;
            pre->next = last;
            pre = groupStart;
            groupStart = nextTemp;
        }
        temp = nextTemp;
    }

    return dummy.next;
}

int main() {
    sl *head = NULL, *tail = NULL;
    int n, k, val;

    printf("enter size of list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("enter node %d: ", i + 1);
        scanf("%d", &val);
        insertNode(&head, &tail, val);
    }

    printf("enter k: ");
    scanf("%d", &k);

    sl* result = reverseKGroup(head, k);

    printList("reversed list", result);

    return 0;
}
