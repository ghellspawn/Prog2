// Code to find the min and max value of a tree.
#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode* left;
    struct bstNode* right;
} bstNode;

bstNode* get_new_node(int data)
{
    bstNode* new_node = (bstNode*)malloc(sizeof(bstNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int find_max(bstNode* root)
{
    bstNode* current = root;

    if(root == NULL)
    {
        printf("Error: Tree is empty\n");
    }
    else if(current->right == NULL)
    {
        return current->data;
    }

    // Search in right subtree.
    return find_max(current->right);
}

int find_min(bstNode* root)
{
    bstNode* current = root;

    if(root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    else if(current->left == NULL)
    {
        return current->data;
    }
    
    // Search in left subtree.
    return find_min(current->left);
}

// Function to insert in a BST, return adress of root node
bstNode* insert(bstNode* root, int data)
{
    if(root == NULL) // empty tree
    {
        root = get_new_node(data);
    }
    else if(data <= root->data) // smaller number goes to left
    {
        root->left = insert(root->left, data);
    }
    else // bigger number goes to right
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int main()
{
    bstNode* root = NULL; // creating an empty tree

    root = insert(root, 15); root = insert(root, 10); root = insert(root, 20);
    root = insert(root, 25); root = insert(root, 8);  root = insert(root, 12);

    int min = find_min(root);
    int max = find_max(root);

    printf("Min: %d\nMax: %d\n", min, max);

    return 0;
}