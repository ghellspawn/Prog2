#include <stdio.h>                                              //Comentários!
#include <stdlib.h>

typedef struct Node                                             //Estrutura base do nó.
{
    int data;
    struct Node* next;
} Node;

Node* head1;
Node* head2;                                                     //Variável global, pode ser acessada em qualquer lugar.

void compare(int b)
{
    Node* temp1 = head2;
    Node* temp2 = head1;
    int c = 0;

    while(temp1 != NULL) //lista B
    {
        while(temp2 != NULL) //lista A
        {
            if(temp1->data == temp2->data)
            {
                c++;
            }
            if(c >= b)
            {
                printf("1\n");
                return;
            }

            temp2 = temp2->next; //avanço em A
        }

        temp1 = temp1->next; //avanço em B
        temp2 = head1; // volta pra cabeça de A
    }

    if(c < b)
    {
        printf("0\n");
    }
}

void print()                                                    //Função que printa os dados
{
    Node* temp1 = head2;
    Node* temp2 = head1;

    printf("A Lista e: ");

    while(temp1 != NULL)                                         //Enquanto a lista não atingir o fim, continue printando.
    {
        printf(" %d", temp1->data);
        temp1 = temp1->next;
    }

    printf("\n");

    while(temp2 != NULL)                                         //Enquanto a lista não atingir o fim, continue printando.
    {
        printf(" %d", temp2->data);
        temp2 = temp2->next;
    }

    printf("\n");
}

void insert(int x, Node **h)                                              //Função que associa os dados
{

    Node* temp = (Node*)malloc(sizeof(Node));                   //Criando os nós

    temp->data = x;                                             //Associando os dados.
    temp->next = *h;                                       //Conectando os nós.
    *h = temp;        
}

int main()
{
    head1 = NULL;                                                //Lista vazia.
    head2 = NULL;

    int a, b;
    scanf("%d", &a);

    int array1[a], i;
    for(i = 0; i < a; i++)
    {
        scanf("%d", &array1[i]);
        insert(array1[i], &head1);
    }

    scanf("%d", &b);

    int array2[b];
    for(i = 0; i < b; i++)
    {
        scanf("%d", &array2[i]);
        insert(array2[i], &head2);
    }

    compare(b);
    // print();
}
