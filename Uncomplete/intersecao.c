#include <stdio.h>                                              
#include <stdlib.h>

typedef struct Node                                             
{
    int data;
    struct Node* next;
} Node;

Node* head1;                                                    
Node* head2;
Node* head3;

void swapNodes(Node** head_ref, struct Node* currX, Node* currY, struct Node* prevY)
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

void insert(int x, Node **h)                                              
{

    Node* temp = (Node*)malloc(sizeof(Node));                   

    temp->data = x;                                             
    temp->next = *h;                                       
    *h = temp;        
}

void print()                                                  
{
    Node* temp = head3;

    while(temp != NULL)                                   
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void intersec()
{
    int i = 0;

    Node* temp1 = head1;
    

    while(temp1 != NULL)                                   
    {
        Node* temp2 = head2;
        while(temp2 != NULL)
        {
            if(temp1->data == temp2->data)
            {
                int flag = 1;
                Node* temp3 = head3;
                while(temp3 != NULL)
                {
                    if(temp1->data == temp3->data)
                    {
                        flag = 0;
                        break;
                    }
                    temp3 = temp3->next;
                }
                if(flag)
                {
                    insert(temp1->data, &head3);
                    i = 1;
                }
                    
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    if(i == 0)
    {
        printf("VAZIO\n");
        return;
    }
    else
    {
        sort(&head3);
        print();
    }
}

int main()
{
    head1 = NULL;                                               
    head2 = NULL;
    head3 = NULL;

    int n;
    int i;

    for(i = 0; i < 20; i++)
    {
        scanf("%d", &n);
        insert(n, &head1);
    }

    for(i = 0; i < 20; i++)
    {
        scanf("%d", &n);
        insert(n, &head2);
    }

    intersec();
    return 0;
}

// TO DO: TRATAR O ERRO DE REPETIÇÕES DE NUMEROS.