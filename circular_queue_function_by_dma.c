#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int enqueue(int a[], int rear, int front);
int dequeue(int a[], int rear, int front);
void display(int a[], int rear, int front);

int main() {
    int front = -1, rear = -1, ch;
    int *a = (int *)malloc(MAX * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n--- CIRCULAR QUEUE MENU ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                rear = enqueue(a, rear, front);
                if (front == -1 && rear != -1) {
                    front = 0;
                }
                break;
            case 2:
                front = dequeue(a, rear, front);
                if (front == -1) {
                    rear = -1;
                }
                break;
            case 3:
                display(a, rear, front);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 4);

    free(a);
    return 0;
}

int enqueue(int a[], int rear, int front) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return rear;
    }

    int val;
    printf("Enter element to enqueue: ");
    scanf("%d", &val);

    if (rear == -1) {
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    a[rear] = val;
    printf("%d inserted successfully.\n", val);
    return rear;
}

int dequeue(int a[], int rear, int front) {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }

    printf("Dequeued element: %d\n", a[front]);

    if (front == rear) {
        return -1;
    }

    return (front + 1) % MAX;
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
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
