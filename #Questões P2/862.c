#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head;

void insert(char x)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = x;
    temp->next = head;
    head = temp;
}

int main()
{
    head = NULL;

    int i, size;
    char seq[9999];

    while(1)
    {
        scanf(" %[^\n]s", seq);

        size = strlen(seq);

        if(size == 1 && seq[0] == '0')
        {   
            return 0;
        }

        for(i = 0; i < size; i++) 
        {

        }

        printf("%s\n", seq);
    }
}


// coisas para fazer:
// passar os valores para lista
// criar um auxiliar para receber a maior quantidade de zeros
// criar um auxiliar para guardar a posição inicial da quantidade de zeros
// criar um auxiliar para guardar a posiçao final da quantidade de zeros
// criar um contador para a quantidade de zeros, a fim de comparálo com a quantidade maior anterior
// manipular a lista
