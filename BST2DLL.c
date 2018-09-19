#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* dll = NULL; // Doubly linked list

struct Node* newItem(int item) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->val = item;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// Function to insert items in BST
struct Node* insertItem(struct Node* node, int val) {
    if(node == NULL)
        return newItem(val);
    if(node->val > val)
        node->left = newItem(val);
    else
        node->right = newItem(val);
    return node;
}

// Function to insert items in Doubly linked list
void insertInDLL(int item, struct Node** dll) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = item;  
    new_node->left = (*dll);
    new_node->right = NULL;
    
    if ((*dll) != NULL) 
        (*dll)->right = new_node;
    
    *dll = new_node;
}

// To fetch elements from BST in sorted manner. Thankfully, we have inorder traversal for it!
void inOrder(struct Node* root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    insertInDLL(root->val, &dll);
    inOrder(root->right);
}

// Funtion to print Doubly linked list
void printDLL(struct Node* dll) {
    if(dll == NULL)
        return;
    printDLL(dll->left);
    printf("%d \n", dll->val);
}

int main() {
    int n, i, item;
    struct Node* root = NULL;
    int firstNode = 1;
    printf("Enter the total number of nodes\n");
    scanf("%d", &n);
    if(n == 0) {
        printf("Empty BST and LinkedList\n");
        return 0;
    }
    printf("Enter the nodes in order (root, left, right)\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &item);
        if(firstNode) {
            root = insertItem(root, item);
            firstNode = 0;
        }
        else
            insertItem(root, item);
    }

    inOrder(root);

    printf("Contents of Doubly LinkedList are:\n");
    printDLL(dll);
}