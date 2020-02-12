#include <stdio.h>                                              //Comentários!
#include <stdlib.h>

typedef struct Node                                             //Estrutura base do nó.
{
    int data;
    struct Node* next;
} Node;

Node* head;                                                     //Variável global, pode ser acessada em qualquer lugar.

void swapNodes(Node** head_ref, struct Node* currX, 
               Node* currY, struct Node* prevY) 
{ 

    *head_ref = currY; 
  

    prevY->next = currX; 
  

    Node* temp = currY->next; 
    currY->next = currX->next; 
    currX->next = temp; 
} 

struct Node* recurSelectionSort(Node* head) 
{ 

    if (head->next == NULL)
    {
        return head; 
    }
        
    Node* min = head; 
  
    Node* beforeMin = NULL; 
    Node* ptr; 
  
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) 
    {
        if (ptr->next->data < min->data) 
        { 
            min = ptr->next; 
            beforeMin = ptr; 
        } 
    } 
  
    if (min != head)
    {
        swapNodes(&head, head, min, beforeMin); 
    }

    head->next = recurSelectionSort(head->next); 
  
    return head; 
} 
   
void sort(Node** head_ref) 
{ 

    if ((*head_ref) == NULL)
    {
        return; 
    } 
        
    *head_ref = recurSelectionSort(*head_ref); 
}

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
        print();
    }
}

int main()
{
    head = NULL;                                                //Lista vazia.

    int n;
    while(scanf("%d", &n) != EOF)
    {
        insert(n);
    }

    sort(&head);

    print();
}