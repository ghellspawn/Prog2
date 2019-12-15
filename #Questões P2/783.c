#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode* left;
    struct bstNode* right;
} bstNode;

// -------------------------------------------------------------------------------------- PRINTS --------------------------------------------------------------------------------

int is_empty (bstNode *root)
{
	if (root == NULL) return 1;
	else return 0;
}

void print_pre_order(bstNode *root)
{
    if (!is_empty(root))
    {
        printf(" ( ");
        printf("%d ", root->data);  

        
        if (root->left == NULL)
        {
            printf(" () ");
        } 

        else
        {
            print_pre_order(root->left);
        }

        if (root->right == NULL)
        {
            printf(" () ");
        } 

        else
        {
            print_pre_order(root->right);
        }

        printf(") ");
    }
}

// -------------------------------------------------------------------------------------- PRINTS --------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------- BST ------------------------------------------------------------------------------------

bstNode* get_new_node(int data)
{
    bstNode* new_node = (bstNode*)malloc(sizeof(bstNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Function to insert in a BST, return adress of root node
bstNode* insert(bstNode* root, int data)
{
    if(root == NULL) // empty tree
    {
        root = get_new_node(data);
    }
    else if(data < root->data) // smaller number goes left
    {
        root->left = insert(root->left, data);
    }
    else // bigger number goes right
    {
        root->right = insert(root->right, data);
    }

    return root;
}

//-------------------------------------------------------------------------------------- BST ------------------------------------------------------------------------------------

int main()
{
    bstNode* root = NULL; // creating an empty tree

    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("----\nAdicionando %d\n  ", n);
        root = insert(root, n);
        print_pre_order(root);
        printf("\n");
    }

    printf("----");

    return 0;
}