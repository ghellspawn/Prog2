#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

typedef struct heap
{
    int size;
    int data[MAX_SIZE];
} heap;

heap* create_heap()
{
    heap* temp = (heap*)malloc(sizeof(heap));

    temp->size = 0;

    return temp;
}

// returns the index of the parent node
int parent(int i) 
{
    return i / 2;
}

// return the index of the left child 
int left_child(int i) 
{
    return 2*i;
}

// return the index of the right child 
int right_child(int i) 
{
    return 2*i + 1;
}

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insert the item at the appropriate position
void insert(heap* temp, int data) 
{
    if (temp->size >= MAX_SIZE) 
    {
        printf("%s\n", "The heap is full. Cannot insert.");
        return;
    }

    // first insert the time at the last position of the array 
    // and move it up
    temp->data[temp->size++] = data;

    // move up until the heap property satisfies
    int i = temp->size;
    while (i != 0 && temp->data[parent(i)] <temp->data[i]) 
    {
        swap(&temp->data[parent(i)], &temp->data[i]);
        i = parent(i);
    }
}

// moves the item at position i of array a
// into its appropriate position
void max_heapify(heap* temp, int i)
{
    // find left child node
    int left = left_child(i);

    // find right child node
    int right = right_child(i);

    // find the largest among 3 nodes
    int largest = i;

    // check if the left node is larger than the current node
    if (left <= temp->size && temp->data[left] > temp->data[largest]) 
    {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= temp->size && temp->data[right] > temp->data[largest]) 
    {
        largest = right;
    }

    // swap the largest node with the current node 
    // and repeat this process until the current node is larger than 
    // the right and the left node
    if (largest != i) 
    {
        int aux = temp->data[i];
        temp->data[i] = temp->data[largest];
        temp->data[largest] = aux;
        max_heapify(temp, largest);
    }

}

// converts an array into a heap
void build_heap(heap* temp) 
{
    int i;
    for (i = temp->size/2; i > 0; i--) 
    {
        max_heapify(temp, i);
    } 
}

// returns the  maximum item of the heap
int get_max(heap* temp) 
{
    return temp->data[1];
}

// deletes the max item and return
int extract_max(heap* temp) 
{
    int max_item = temp->data[1];

    // replace the first item with the last item
    temp->data[1] = temp->data[temp->size--];

    // maintain the heap property by heapifying the 
    // first item
    max_heapify(temp, 1);
    return max_item;
}

// prints the heap
void print_heap(heap* temp, int i, int first) 
{
    if(i == temp->size + 1) // cheguei no final da heap
    {
        printf("\n");
        return;
    }

    if(first == 0) // primeiro elemento
    {
        printf("%d", temp->data[i]);
    }

    else
    {
        printf(" | %d", temp->data[i]);
    }

    first = 1;
    print_heap(temp, i + 1, first);
}

// function that does the heap sort
void heap_sort(heap* temp)
{
    int i;
    for(i = temp->size; i >= 2; i--)
    {
        printf("Maior elemento neste passo: %d\n", temp->data[1]);
        swap(&temp->data[1], &temp->data[i]);

        temp->size--;

        max_heapify(temp, 1);

        printf("Estado Atual da Heap: ");
        print_heap(temp, 1, 0);
    }
}

int main() 
{
    heap *new_heap = create_heap();

    int input, i = 1, non_inicial_state = 0;

    while(scanf("%d", &input) != EOF)
    {
        new_heap->data[i] = input;

        if(non_inicial_state == 0) // significa que estou no estado inicial
        {
            printf("Estado inicial: %d", input);
        }
        else
        {
            printf(" | %d", input); // não estou mais no estado inicial
        }
        
        non_inicial_state = 1, i++;
    }

    new_heap->size = i;
    printf("\n");

    build_heap(new_heap);
    new_heap->size = i - 1;   // new_heap->size = i--;
    
    printf("Estado Atual da Heap: ");
    print_heap(new_heap, 1, 0);

    heap_sort(new_heap);
    printf("Resultado Final: ");

    new_heap->size = i - 1;
    print_heap(new_heap, 1, 0);
    printf("\n");

    return 0;
}