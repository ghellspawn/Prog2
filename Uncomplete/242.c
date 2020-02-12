#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int value;
    struct element *next;
    struct element *prev;
} element;

typedef struct hash
{
    struct element *table[200];
    int qtd;
} hash;

hash *create_hash(int size)
{
    int i;

    hash *new_hash = (hash*) malloc(sizeof(hash));

    for (i = 0; i < size; i++)
    {
        new_hash->table[i] = NULL;
    }

    return new_hash;
}

element *create_element(int item)
{
    element* new_element = (element*) malloc(sizeof(element));

    new_element -> value = item;
    new_element -> next = NULL;
    new_element -> prev = NULL;

    return new_element;
}

void print_hash(hash *new_hash, int size, int i, int flag)
{
    if (size == i)
    {
        return;
    }

    element *temp = new_hash->table[i];
    while (temp != NULL)
    {
        if (flag == 0) //flag que determina o inicio
        {
            printf("%d -> %d", i, temp->value);
        }
        else
        {
            printf(" -> %d", temp->value);
        }

        flag = 1;
        temp = temp->next;
    }

    if (temp == NULL && flag == 1)
    {
        printf(" -> \\\n");

    }
    else
    {
        printf("%d -> \\\n", i);
    }
    
    print_hash(new_hash, size, i + 1, 0);
}

element* insert(element *head, int item)
{
    element *new_element = create_element(item); 
    element *temp = head;
    
    if(temp != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_element;
        new_element->prev = temp;

        return head;
    }
    else
    {
        return new_element;
    }
    
}

void remove_hash_table(hash *new_hash, int size)
{
    int i = 0;
    hash *remove_hash = new_hash->table[size];

    while (i < size)
    {
        if (new_hash->table[i] != NULL)
        {
            element *aux = new_hash->table[i];

            while (aux->next != NULL)
            {
                aux = aux->next;               
            }

            while (aux->prev != NULL)
            {
                element *temp = aux;
                aux = aux->prev;
                free(temp);
            }
        }
        
        i++;
    }

    free(remove_hash);
}

int boundaries(int key, int item)
{   
    return item % key;
}

void put(hash *new_hash, int key_hash, int item, int size)
{
    if (new_hash == NULL || new_hash->qtd == size)
    {
        return;
    }

    int key = boundaries(key_hash, item);

    if (new_hash->table[key] == NULL)
    {
        element *head = NULL;

        head = insert(head, item);

        new_hash->table[key] = head;
        new_hash->qtd++;
    }
    else
    {
        element *aux = new_hash->table[key];
        aux = insert(aux, item);

        new_hash->qtd++;
    }  
}

int main()
{
    int n, count = 0;

    scanf("%d", &n);

    while(count < n)
    {
        int address, qtd_keys;
        scanf("%d%d", &address, &qtd_keys);

        hash *new_hash = create_hash(qtd_keys);

        int i;
        for (i = 0; i < qtd_keys; i++)
        {
            int number;
            scanf("%d", &number);
            put(new_hash, address, number, qtd_keys);
        }

        print_hash(new_hash, address, 0, 0);
        remove_hash_table(new_hash, address);

        printf("\n");

        count++;
    }

    return 0;
}