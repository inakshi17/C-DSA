#include <stdio.h>

#define max 10
int enqueue(int [], int, int);
int dequeue(int [], int, int);
void display(int [], int, int);

int main() {
    int a[max], front = -1, rear = -1, ch;
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
    if ((rear+1)%max==front) {
        printf("Queue Overflow!\n");
        return rear;
    }
    printf("Enter element to enqueue: ");
    scanf("%d", &val);
    rear=(rear+1)%max;
    a[rear] = val;
    return rear;
}

int dequeue(int a[], int rear, int front) {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    printf("Dequeued element: %d\n", a[front]);
    if(front==rear){ return -1;}
    front =(front+1)%10;
    return front;
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
        i = (i + 1) % max;
    }
    printf("\n");
}
