#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    // If the list is empty, point newNode to itself
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to the new node
        *head = newNode;      // New node becomes the head
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    // If the list is empty, point newNode to itself
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to the new node
    }
}

// Function to traverse and print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Traverse the list and print each node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we reach the head again
    printf("(head)\n");
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *temp = *head, *prev;

    // If head node holds the key
    if (temp->data == key) {
        // Find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next; // Update the last node's next pointer
        free(*head);                // Free the old head
        *head = temp->next;         // Update the head to the next node
        return;
    }

    // Search for the key and track the previous node
    prev = temp;
    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted was found
    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the circular linked list
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtBeginning(&head, 5);

    printf("Circular Linked List: \n");
    printList(head);

    // Delete a node
    printf("Deleting node with value 30...\n");
    deleteNode(&head, 30);
    printList(head);

    return 0;
}
