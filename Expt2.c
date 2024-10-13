#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define maximum size for the expression and stack
#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = item;
}

// Function to pop an item from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';  // Return null character if stack is empty
    }
    return s->items[s->top--];
}

// Function to peek the top item of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';  // Return null character if stack is empty
    }
    return s->items[s->top];
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If the character is ')', pop and output from the stack
        // until an '(' is encountered
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s);  // Remove '(' from the stack
            }
        }
        // An operator is encountered
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline character
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
