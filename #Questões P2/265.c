#include <stdio.h>                                              //Comentários!
#include <stdlib.h>
#include <string.h>

typedef struct Node                                             //Estrutura base do nó.
{
    int data;
    struct Node* next;
} Node;

Node* head;                                                     //Variável global, pode ser acessada em qualquer lugar.

void insert(char frase[], int size)                                              //Função que associa os dados
{
    int i;
    for(i = 0; i < size; i++)
    {
        Node* temp = (Node*)malloc(sizeof(Node));                   //Criando os nós

        temp->data = frase[i];                                            //Associando os dados.
        temp->next = head;                                       //Conectando os nós.
        head = temp;
    }
           
}

void print()                                                    //Função que printa os dados
{
    Node* temp = head;

    printf("A Lista e: ");

    while(temp != NULL)                                         //Enquanto a lista não atingir o fim, continue printando.
    {
        printf(" %c", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void read(char frase[])
{
    scanf(" %[^\n]s", frase);
    int size = strlen(frase);

    insert(frase, size);
    print();
    
}

int main()
{
    head = NULL;                                                //Lista vazia.

    char frase[1000];

    read(frase);
}