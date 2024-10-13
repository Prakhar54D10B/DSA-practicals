#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyCircularLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

struct DoublyCircularLinkedList* createList() {
    struct DoublyCircularLinkedList* list = (struct DoublyCircularLinkedList*)malloc(sizeof(struct DoublyCircularLinkedList));
    list->head = NULL;
    return list;
}

void insert(struct DoublyCircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* tail = list->head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
}

void display(struct DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

void deleteNode(struct DoublyCircularLinkedList* list, int key) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = list->head;
    do {
        if (current->data == key) {
            if (current->next == current) {
                free(current);
                list->head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == list->head) {
                    list->head = current->next;
                }
                free(current);
            }
            return;
        }
        current = current->next;
    } while (current != list->head);
    printf("Node not found.\n");
}

int main() {
    struct DoublyCircularLinkedList* dcll = createList();
    
    printf("List after insertion of 1 \n");
    insert(dcll, 1);
    display(dcll);
    printf("List after insertion of 2 \n");
    insert(dcll, 2);
    display(dcll);
    printf("List after insertion of 3 \n");
    insert(dcll, 3);
    
    display(dcll);
    
    deleteNode(dcll, 2);
    
    printf("List after deletion of 2: \n");
    display(dcll);
    
    return 0;
}
