// Code for a level order traversal.
#include <bits/stdc++.h>

using namespace std;

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

void level_order(bstNode *root)
{
    if(root == NULL)
    {
        return;
    }
   
   queue<bstNode*> q;
   q.push(root);

    // While the is at leat one discovered node
    while(!q.empty())
    {
        bstNode* current = q.front();
        cout<<current->data<<" ";

        if(current->left != NULL)
        {
            q.push(current->left);
        }
        if(current->right != NULL)
        {
            q.push(current->right);
        }

        q.pop(); // removing the element at front;
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

    return 0;
}