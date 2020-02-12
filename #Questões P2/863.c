#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
  
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
  
int s_size(s_node** root)
{
    int cont = 0;
    s_node* temp = *root;

    while(temp != NULL)
    {
        cont++;
        temp = temp->next;
    }

    return cont;
} 
 
int main() 
{ 
    s_node* back_s = NULL;
    s_node* forward_s = NULL;

    char string[255];

    while(scanf(" %[^\n]s", string) != EOF)
    {
        if(strcmp(string, "ENTER") == 0)
        {
            pop(&forward_s);
            push(&back_s, 1);
        }
        else if(strcmp(string, "BACK") == 0)
        {
            push(&forward_s, 1);
            pop(&back_s);
        }
        else if(strcmp(string, "FORWARD") == 0)
        {
            push(&back_s, 1);
            pop(&forward_s);
        }
    }

    int size_b = s_size(&back_s);
    int size_f = s_size(&forward_s);

    printf("BACK: %d\nFORWARD: %d\n", size_b - 1, size_f);
  
    return 0; 
}