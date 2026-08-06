#include <stdio.h>
#include <stdlib.h>

#define max 10
int enqueue(int [], int, int);
int dequeue(int [], int, int);
void display(int [], int, int);

int main() {
    int  front = -1, rear = -1, ch;
    int *a= (int *)malloc(max*sizeof(int));
    do {
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit");
        printf("\nenter your choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                rear = enqueue(a, rear, front);
                if (rear != -1 && front == -1) {
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
        }
    } while (ch <4 && ch >0);
    return 0;
}
int enqueue(int a[], int rear, int front) {
    int val;
    if (rear == max - 1) {
        printf("Queue Overflow!\n");
        return rear;
    }
    printf("Enter element to enqueue: ");
    scanf("%d", &val);
    rear++;
    a[rear] = val;
    printf("%d inserted successfully.\n", val);
    return rear;
}

int dequeue(int a[], int rear, int front) {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    printf("Dequeued element: %d\n", a[front]);
    front++;
    if (front > rear) {
        return -1;
    }
    return front;
}
void display(int a[], int rear, int front) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    printf("\n");
}
