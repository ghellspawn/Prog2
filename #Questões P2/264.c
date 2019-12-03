#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* Reverse(Node* head)
{
    Node *current, *prev, *next;

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

Node* Insert(Node* head, int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* temp1 = head;

        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        temp1->next = temp;
    }
    
    return head;
}

void Print(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    //head = Intert | tenho que colocar um for

    head = Reverse(head);
    print(head);
}