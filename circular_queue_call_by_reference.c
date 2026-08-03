#include <stdio.h>

#define MAX 10
void enqueue(int a[], int *rear, int *front);
void dequeue(int a[], int *rear, int *front);
void display(int a[], int rear, int front);

int main() {
    int a[MAX], front = -1, rear = -1, ch;
    do {
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit");
        printf("\nenter your choice : ");
        scanf("%d", &ch);

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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch < 4 && ch > 0);
    return 0;
}
void enqueue(int a[], int *rear, int *front) {
    if ((*rear + 1) % MAX == *front) {
        printf("Queue Overflow!\n");
        return;
    }
    int val;
    printf("Enter element to enqueue: ");
    scanf("%d", &val);
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % MAX;
    a[*rear] = val;
}

void dequeue(int a[], int *rear, int *front) {
    if (*front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued element: %d\n", a[*front]);
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % MAX;
    }
}

void display(int a[], int rear, int front) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", a[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
