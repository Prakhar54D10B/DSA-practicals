#include <stdio.h>

#define MAX 5

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                if (top == MAX - 1) {
                    printf("Stack overflow! Cannot push more elements.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                    printf("Pushed %d onto the stack.\n", value);
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    printf("Stack underflow! Cannot pop any elements.\n");
                } else {
                    printf("Popped %d from the stack.\n", stack[top]);
                    top--;
                }
                break;

            case 3: // Peek
                if (top == -1) {
                    printf("Stack is empty! Cannot peek.\n");
                } else {
                    printf("Top element is %d.\n", stack[top]);
                }
                break;

            case 4: // Check if Empty
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 5: // Check if Full
                if (top == MAX - 1) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;

            case 6: // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
