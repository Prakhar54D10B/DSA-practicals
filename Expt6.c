#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;               // Data part
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push operation to add an item to the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;    // Point the new node to the current top
    *top = newNode;          // Update top to the new node
    printf("%d pushed to stack\n", data);
}

// Pop operation to remove an item from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = *top;      // Store the top node
    int poppedData = temp->data;   // Get the data of the top node
    *top = (*top)->next;           // Update top to the next node
    free(temp);                    // Free the popped node
    return poppedData;             // Return the popped data
}

// Peek operation to get the top item without removing it
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data; // Return the data of the top node
}

// Check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Driver code for testing
int main() {
    struct Node* stack = NULL; // Initialize stack

    // Push data to the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(stack)); // Peek the top element

    printf("%d popped from stack\n", pop(&stack)); // Pop the top element
    printf("Top element is %d\n", peek(stack));    // Peek again

    return 0;
}
