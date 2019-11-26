#include <stdio.h>                                              //Comentários!
#include <stdlib.h>

typedef struct Node                                             //Estrutura base do nó.
{
    int data;
    struct Node* next;
} Node;

Node* head;                                                     //Variável global, pode ser acessada em qualquer lugar.

void insert(int x)                                              //Função que associa os dados
{
    Node* temp = (Node*)malloc(sizeof(Node));                   //Criando os nós

    temp->data = x;                                             //Associando os dados.
    temp->next = head;                                          //Conectando os nós.
    head = temp;        
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

void read(int n, int i, int x)
{
    printf("Quantos numeros serao lidos?\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Digite o numero: \n");
        scanf("%d", &x);

        insert(x);
        print(x);
    }
}

int main()
{
    head = NULL;                                                //Lista vazia.

    int n, x;

    read(n, 0, x);
}