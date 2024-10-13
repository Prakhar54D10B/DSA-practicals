#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct a balanced BST from a sorted array
struct TreeNode* sortedArrayToBST(int* arr, int low, int high) {
    if (low > high) {
        return NULL;
    }

    // Get the middle element and make it the root
    int mid = low + (high - low) / 2;
    struct TreeNode* root = createNode(arr[mid]);

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(arr, low, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, high);

    return root;
}

// Function to search for a given key in the BST
int search(struct TreeNode* root, int key) {
    if (root == NULL) {
        return 0;  // Key not found
    }
    if (root->val == key) {
        return 1;  // Key found
    }
    // If key is greater than root's value, search in the right subtree
    if (key > root->val) {
        return search(root->right, key);
    }
    // If key is smaller than root's value, search in the left subtree
    return search(root->left, key);
}

// Function to find the minimum value node in the BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a key from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: get the inorder successor
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val; // Copy the inorder successor's value
        root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
    }
    return root;
}

// Function to free the BST (to prevent memory leaks)
void freeBST(struct TreeNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// Function to perform in-order traversal
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[7];
    printf("Enter 7 elements for array binary search tree implementation:\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]); // Read integers from user
    }

    // Sort the array
    qsort(arr, 7, sizeof(int), compare);

    // Build the BST
    struct TreeNode* bstRoot = sortedArrayToBST(arr, 0, 6); // Indexes for 7 elements

    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Search for an element\n");
        printf("2. Delete an element\n");
        printf("3. Display BST in-order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to search in the BST: ");
                scanf("%d", &key);
                printf("Searching for %d: %s\n", key, search(bstRoot, key) ? "Found" : "Not Found");
                break;
            case 2:
                printf("Enter an element to delete from the BST: ");
                scanf("%d", &key);
                bstRoot = deleteNode(bstRoot, key);
                printf("Element %d deleted (if it was found).\n", key);
                break;
            case 3:
                printf("BST in-order traversal: ");
                inorderTraversal(bstRoot);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the BST
    freeBST(bstRoot);

    return 0;
}
