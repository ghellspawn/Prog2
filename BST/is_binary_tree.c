#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648


typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

int is_bst_util(node* root, int min_value, int max_value)
{
    if(root == NULL)
    {
        return 1;
    }
    if(root->data > min_value && root->data < max_value && is_bst_util(root->left, min_value, root->data) && is_bst_util(root->right, root->data, max_value))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_binary_tree(node* root, int min_value, int max_value)
{
    return is_bst_util(root, INT_MAX, INT_MIN);
}

int main()
{
    node* root = NULL; // creatin an empty tree

    // Colocar o código de insert
    
    int return_da_bst;

    if(return_da_bst = 1)
    {
        printf("É uma árvore de busca binária\n");
    }
    else
    {
        printf("Não é uma árvore de busca binária\n");
    }
    
    return 0;
}