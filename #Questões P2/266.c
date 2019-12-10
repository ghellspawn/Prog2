#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head;

void reverse() 
{ 
    Node* current = head; 
    Node *prev = NULL, *next = NULL; 

    while (current != NULL) 
    { 

        next = current->next; 

        current->next = prev; 

        prev = current; 
        current = next; 
    } 

    head = prev; 
}

void print()                                                    //Função que printa os dados
{
    Node* temp = head;

    printf("A Lista e: ");

    while(temp != NULL)                                         //Enquanto a lista não atingir o fim, continue printando.
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insert(int x)                                              //Função que associa os dados
{
    Node* temp = (Node*)malloc(sizeof(Node));                   //Criando os nós

    temp->data = x;                                             //Associando os dados.
    temp->next = head;                                          //Conectando os nós.
    head = temp;        
}

int main()
{
    head = NULL;

    int n;

    while(scanf("%d", &n) != EOF)
    {
        insert(n);
    }

    reverse();
}