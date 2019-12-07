#include <stdio.h>                                              //Comentários!
#include <stdlib.h>
#include <string.h>

typedef struct Node                                             //Estrutura base do nó.
{
    int data;
    char letter;
    struct Node* next;
} Node;

Node* head;                                                     //Variável global, pode ser acessada em qualquer lugar.

void insert(int x, char y)                                              //Função que associa os dados
{
    Node* temp = (Node*)malloc(sizeof(Node));                   //Criando os nós

    temp->data = x;   
    temp->letter = y;                                          //Associando os dados.
    temp->next = head;                                          //Conectando os nós.
    head = temp;        
}

void print()                                                    //Função que printa os dados
{
    Node* temp = head;

    while(temp != NULL)                                         //Enquanto a lista não atingir o fim, continue printando.
    {
        printf("%c %d\n", temp->letter, temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    head = NULL;                                                //Lista vazia.

    int i;
    char frase[9999];

    scanf(" %[^\n]s", frase);

    int asc[256] = {0};

    for(i = 0; i < strlen(frase); i++)
    {
        asc[frase[i]]++;
    }

    for(i = 0; i < 256; i++)
    {
        if(asc[i] != 0)
        {
            insert(asc[i], i);
        }
    }

    print();
}
