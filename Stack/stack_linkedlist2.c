#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct StackNode 
{ 
    int data; 
    struct StackNode* next; 
} s_node;
  
s_node* new_node(int data) 
{ 
    s_node* stackNode = (s_node*)malloc(sizeof(s_node));

    stackNode->data = data; 
    stackNode->next = NULL; 

    return stackNode; 
} 
  
int is_empty(s_node* root) 
{ 
    return !root; 
} 
  
void push(s_node** root, int data) 
{ 
    s_node* stackNode = new_node(data); 
    stackNode->next = *root; 
    *root = stackNode;

    printf("%d pushed to stack\n", data); 
}
  
int pop(s_node** root) 
{ 
    if (is_empty(*root))
    {
        return INT_MIN;
    }

    s_node* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 

    free(temp); 
  
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (is_empty(root))
    {
        return INT_MIN;
    }
        
    return root->data; 
}
  
int main() 
{ 
    s_node* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    printf("%d popped from stack\n", pop(&root)); 
  
    printf("Top element is %d\n", peek(root)); 
  
    return 0; 
}