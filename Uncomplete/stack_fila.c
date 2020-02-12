#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAX 1000

typedef struct Node                                            
{
    int data;
    struct Node* next;
} Node;

typedef struct StackNode 
{ 
    int current_size;
    Node* heads[MAX]; 
} s_node;

void print(s_node* stack)                                       
{
    Node* temp = stack->heads[stack->current_size - 1];
    stack->current_size--;
    
    int flag = 0;
    while(temp != NULL)                                         
    {
        if(flag == 0)
        {
            flag = 1;
            printf("%d", temp->data);
        }
        else
        {
            printf(" %d", temp->data);
        }

        temp = temp->next;
    }

    printf("\n");
}
  
int is_empty(s_node* root) 
{ 
    return !root; 
} 
  
void push(s_node* stack, Node* head)
{ 
    stack->heads[stack->current_size++] = head;
}

void pop(s_node* stack) 
{ 
    if(stack->current_size == 0)
    {
        printf("EMPTY STACK\n");
        return;
    } 

    print(stack);
}

Node *create_node(int item) 
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = item;
    new_node->next = NULL;

    return new_node;
}

Node *insert(Node *head, int item)
{
    Node *new_node = create_node(item); 
    Node *temp = head;

    if (head == NULL) 
    {
        return new_node;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;

    // printf("%d\n", head->data);
    return head;    
}

s_node* create_new_stack()
{
    s_node* temp = (s_node*) malloc(sizeof(s_node));
    temp->current_size = 0;

    int i;
    for(i = 0; i < MAX; i++)
    {
        temp->heads[i] = NULL;
    }

    return temp;
}
  
int main() 
{ 
    char string[4], flag;
    int n;

    s_node* stackzada = create_new_stack();

    while(scanf(" %s", string) != EOF)
    {
        if(strcmp(string, "PUSH") == 0)
        {
            Node* head = NULL;

            while(scanf("%d%c", &n, &flag) && flag != '\n')
            {
                head = insert(head, n);
            }

            head = insert(head, n);
            push(stackzada, head);
        }

        if (strcmp(string, "POP") == 0)
        {
            // printf("%d\n", stackzada->heads[0]->data);
            pop(stackzada);
        }
        
    }
  
    return 0;
}