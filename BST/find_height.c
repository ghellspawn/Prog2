// Code to find the height of an tree.
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(bstNode* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

int search(bstNode* root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
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
    bstNode* root = NULL; // creatin an empty tree

    root = insert(root, 15); root = insert(root, 10); root = insert(root, 20);
    root = insert(root, 25); root = insert(root, 8);  root = insert(root, 12);

    int h = height(root);

    printf("Height = %d\n",h);

    return 0;
}