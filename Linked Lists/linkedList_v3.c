//Código que insere um nó em uma posição 'n'.

#include <stdio.h>      
#include <stdlib.h>

typedef struct Node                                             
{
    int data;
    struct Node* next;
} Node;

Node* head;

void print()
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

}

void insert(int data, int n)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));

    temp1->data = data;
    temp1->next = NULL;

    if(n == 1) //Se cair na primeira posição/inicio
    {
        temp1->next = head; //temp1 vai pra head
        head = temp1; //e head agora vira temp1

        return;
    }

    Node* temp2 = head;

    int i;
    for(i = 0; i < n - 2; i++) //to traverse temp2 through the nodes
    {
        temp2 = temp2->next; //to point temp2 to (n-1)th node after loop
    }

    temp1->next = temp2->next; // point new (nth)node to next node
    temp2->next = temp1; // to point the previous( n-1 th) node to new node
}

int main()
{
    head = NULL; //Lista vazia

    insert(2,1); //Lista: 2
    insert(3,2); //Lista: 2, 3
    insert(4,1); //Lista: 4, 2, 3
    insert(5,2); //Lista: 4, 5, 2, 3

    print();
}