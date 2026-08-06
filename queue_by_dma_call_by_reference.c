#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void enqueue(int *a, int *rear, int *front);
void dequeue(int *a, int *rear, int *front);
void display(const int *a, int rear, int front);

int main() {
    int front = -1, rear = -1, ch;
    int *a = (int *)malloc(MAX * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;

        switch (ch) {
            case 1:
                enqueue(a, &rear, &front);
                break;
            case 2:
                dequeue(a, &rear, &front);
                break;
            case 3:
                display(a, rear, front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (ch != 4);

    free(a);
    return 0;
}

void enqueue(int *a, int *rear, int *front) {
    if (*rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    int val;
    printf("Enter element: ");
    scanf("%d", &val);

    if (*front == -1) {
        *front = 0;
    }

    (*rear)++;
    *(a + *rear) = val; 
    
    printf("%d inserted successfully.\n", val);
}

void dequeue(int *a, int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Dequeued element: %d\n", *(a + *front));
    (*front)++;

    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void display(const int *a, int rear, int front) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}
