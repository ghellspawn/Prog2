#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head;

void compare(int biggest, int ini, int end, int aux, int posiAt, int i)
{
    int r1, r2;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0) // o valor atual é 0
        {
            if(i == 0) // estou começando o streak de 0's
            {
                ini = posiAt; // posição inicial da sequência recebe o valor da posição atual da lista
            }
            
            i++; // achei um 0, i++
            aux = i; // aux recebe a quantidade atual de 0's
            posiAt++; // avanço na posição
        }
        else // o valor atual é 1
        {
            if(i > 0) // se i for maior que 0, significa que eu to em um streak de 0's
            {
                end = posiAt - 1; // posição final da sequencia recebe o valor da posição atual da lista

                if(aux > biggest)
                {
                    biggest = aux;
                    r1 = ini;
                    r2 = end;
                }

                i = 0;  // reseto a quantiade de i's achadas
            }

            posiAt++;
        }

        temp = temp->next;
    }

    printf("%d %d\n", r1, r2);

    head = NULL;
}

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

    while(1) // enquanto for verdadeiro
    {
        scanf(" %[^\n]s", seq);

        size = strlen(seq);

        if(size == 1 && seq[0] == '0') // a entrada foi '0'?
        {   
            return 0; // se sim, pare de ler
        }
        else // caso contrário, pegue a entrada e bote na lista
        {
            for(i = 0; i < size; i++) 
            {
                if(seq[i] == 49)
                {
                    insert(1);
                }
                else
                {
                    insert(0);
                } 
            }

            reverse();
            
            compare(-1, 0, 0, 0, 0, 0);
        }  
    }
}


// 49 = 1
// 48 = 0