// Stack - Linked list based implementation.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* top = NULL;

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
        return;
    }

    temp = top;
    top = top->next;

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

int main()
{

}