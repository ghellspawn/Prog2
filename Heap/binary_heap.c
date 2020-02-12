#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

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
        printf("%s\n", "The heap is full. Cannot insert");
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
void min_heapify(heap* temp, int i)
{
    // find left child node
    int left = left_child(i);

    // find right child node
    int right = right_child(i);

    // find the largest among 3 nodes
    int largest = i;

    // check if the left node is larger than the current node
    if (left <= temp->size && temp->data[left] < temp->data[largest]) 
    {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= temp->size && temp->data[right] < temp->data[largest]) 
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
        min_heapify(temp, largest);
    }

}

// converts an array into a heap
void build_heap(heap* temp) 
{
    int i;
    for (i = temp->size/2; i > 0; i--) 
    {
        min_heapify(temp, i);
    } 
}

// returns the  maximum item of the heap
int get_min(heap* temp) 
{
    return temp->data[1];
}

// deletes the max item and return
int extract_min(heap* temp) 
{
    int max_item = temp->data[1];

    // replace the first item with the last item
    temp->data[1] = temp->data[temp->size--];

    // maintain the heap property by heapifying the 
    // first item
    min_heapify(temp, 1);
    return max_item;
}

// function that does the heap sort
void heap_sort(heap* temp)
{
    int i;
    for(i = temp->size; i >= 2; i--)
    {
        swap(&temp->data[1], &temp->data[i]);

        temp->size--;

        min_heapify(temp, 1);
    }
}

// prints the heap
void print_heap(heap* temp) 
{
    int i;
    for (i = 1; i <= temp->size; i++) 
    {
        printf("%d\n", temp->data[i]);
    }
    printf("\n");
}


int main() 
{
    int qtd;
    scanf("%d", &qtd);

    int cont = 0;

    while(cont < qtd)
    {
        heap* temp = create_heap(); // IMPORTANTE!

        int n;
        scanf("%d", &n);

        int i;

        int aux[n];
        for(i = 1; i < n + 1; i++)
        {
            scanf("%d", &temp->data[++temp->size]); // IMPORTANTE!
            aux[i] = temp->data[temp->size];
        }

        build_heap(temp);

        heap_sort(temp);

        int similarities = 0;
        for(i = 1; i < n + 1; i++)
        {
            if(aux[i] == temp->data[i])
            {
                similarities++;
            }
        }

        printf("%d\n", similarities);

        cont++;
    }

    return 0;
}