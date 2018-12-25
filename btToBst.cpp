/*
Binary Tree to Binary Search Tree Conversion
Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that keeps the original structure of Binary Tree.
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct Node {
int data;
struct Node* left;
struct Node* right;
};

struct Node* newNode(int data) {
    struct Node *tmp = new struct Node;
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inorderFilling(struct Node *root, vector<int> &inorder) {
    if(root == NULL)
        return;
    inorderFilling(root->left, inorder);
    inorder.push_back(root->data);
    inorderFilling(root->right, inorder);
}

void inorderToBst(struct Node *root, int *index, vector<int> inorder){
    if(root == NULL)
        return;
    inorderToBst(root->left, index, inorder);

    root->data = inorder[*index];
    (*index)++;

    inorderToBst(root->right, index, inorder);
}

void printInorder (struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout<<node->data<<" "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 

void binaryToBst(struct Node *root) {
    if(root == NULL)
        return;
    
    vector<int> inorder;

    inorderFilling(root, inorder);
    sort(inorder.begin(), inorder.end());

    int i = 0;
    inorderToBst(root, &i, inorder);

    printInorder(root);
}

int main() {
    struct Node *root = NULL;
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
    binaryToBst(root);
    return 0;
}