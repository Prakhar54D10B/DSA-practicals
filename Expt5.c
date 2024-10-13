#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
/* Global variables */
struct Node *head = NULL;

/* Function to display the linked list */
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Function to add a new node to the end of the list */
void append(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Function to remove a node with a specific value */
void removeNode(int val) {
    if (head == NULL) {
        printf("Underflow: List is empty.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", val);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", val);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", val);
}

/* Function to search for a node with a specific value */
void search(int val) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element %d is found.\n", val);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found.\n", val);
}

int main() {
    while (1) {
        int ch, val;
        printf("ENTER CHOICE:\n");
        printf("1. Append \n2. Delete\n3. Display\n4. Search\n5. EXIT\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &val);
                append(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                removeNode(val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                // Free all nodes before exiting
                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}
