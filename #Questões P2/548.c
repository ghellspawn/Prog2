// Stack - Linked list based implementation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* top;

void insert_list(int x)                                              
{
    node* temp = (node*)malloc(sizeof(node));                   

    temp->data = x;                                             
    temp->next = top;                                          
    top = temp;        
}

void push(int x)
{
    node* temp = (node*)malloc(sizeof(node));

    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop()
{
    node* temp;

    if(top == NULL)
    {
        printf("EMPTY STACK\n");
        return;
    }

    temp = top;
    top = top->next;
    // falta printar a stack

    free(temp);
}

void print()
{
    node* temp = top;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int is_empty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top_f()
{
    return(top->data);
}

node* reverse(node* head)
{
    node *current, *prev, *next;

    current = head;
    prev = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    
    return head;
}

int main()
{
    char string[10];
    int n;

    while(scanf(" %[^\n]s", string) != EOF)
    {
        if(strcmp(string, "PUSH") == 0)
        {
            top = NULL;

            while(scanf("%d", &n) != EOF)
            {
                // daria insert em uma lista
            }

            // depois daria push do conteudo da lista no stack
        }

        if(strcmp(string, "POP") == 0)
        {
            
        }
    }
}

// é uma pilha com listas, não uma pilha normal.