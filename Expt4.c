#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    int *arr;
} Queue;

Queue* createQueue(int s) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = s;
    q->arr = (int *)malloc(s * sizeof(int));
    return q;
}

void enQueue(Queue *q, int value) {
    if ((q->front == 0 && q->rear == q->size - 1) || ((q->rear + 1) % q->size == q->front)) {
        printf("\nQueue is Full\n");
        return;
    }

    if (q->front == -1) { // Insert First Element
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    } else if (q->rear == q->size - 1 && q->front != 0) {
        q->rear = 0;
        q->arr[q->rear] = value;
    } else {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int deQueue(Queue *q) {
    if (q->front == -1) {
        printf("\nQueue is Empty\n");
        return INT_MIN;
    }

    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == q->size - 1) {
        q->front = 0;
    } else {
        q->front++;
    }

    return data;
}

void displayQueue(Queue *q) {
    if (q->front == -1) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nElements in Circular Queue are: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    } else {
        for (int i = q->front; i < q->size; i++)
            printf("%d ", q->arr[i]);

        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int size, choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    Queue *q = createQueue(size);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enQueue(q, value);
                break;
            case 2:
                value = deQueue(q);
                if (value != INT_MIN)
                    printf("Deleted value = %d\n", value);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                free(q->arr);
                free(q);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
