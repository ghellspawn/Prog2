#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5000000
#define MAX_QUEUE_SIZE 5000000

typedef struct adj_list
{
    int data;
    struct adj_list *next;
} adj_list;

typedef struct graph
{
    adj_list *vertices[MAX_SIZE];
    short visited[MAX_SIZE];
} graph;

typedef struct node 
{
	int item;
	struct node *next;
	struct node *previous;
}NODE;

typedef struct queue 
{
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
}queue;

// --------------------------------------------------  QUEUE -----------------------------

queue* create_queue()
{
    queue *new_queue = (queue*) malloc(sizeof(queue));
    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_QUEUE_SIZE - 1;
    return new_queue;
}

int is_empty(queue *queue)
{
    return !(queue->current_size);
}

void enqueue(queue *queue, int item)
{
    if (queue->current_size >= MAX_QUEUE_SIZE) 
    {
        printf("Queue overflow");
    } 
    else 
    {
        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int dequeue(queue *queue)
{
    if (is_empty(queue)) 
    {
        printf("Queue underflow");
        return -1;
    } 
    else 
    {
        int dequeued = queue->items[queue->head];
        queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
        queue->current_size--;
        return dequeued;
    }
}

// --------------------------------------------------  QUEUE -----------------------------

void bfs(graph *Grafo, int source, int wanted)
{
    queue *queue = create_queue();
    int dequeued, flag = 0;
    adj_list *adj_list = Grafo->vertices[source];
    Grafo->visited[source] = 1;
    enqueue(queue, source);

    while(!is_empty(queue))
    {
        dequeued = dequeue(queue);
        adj_list = Grafo->vertices[dequeued];
        while(adj_list != NULL)
        {
            if(!Grafo->visited[adj_list->data])
            {
                if(adj_list->data == wanted && flag == 0)
                {
                    printf("EXISTE\n");
                    flag = 1;
                }

                //printf("%d\n", adj_list->data);
                Grafo->visited[adj_list->data] = 1;
                enqueue(queue, adj_list->data);
            }

            adj_list = adj_list->next;
        }
    }

    if(flag == 0)
        printf("NAO EXISTE\n");
    
}

void dfs(graph *Grafo, int source)
{
    Grafo->visited[source] = 1;
    printf("%d\n", source);

    adj_list *adj_list = Grafo->vertices[source];

    while(adj_list != NULL)
    {
        if(!Grafo->visited[adj_list->data])
        {
            dfs(Grafo, adj_list->data);
        }

        adj_list = adj_list->next;
    }
}

void print_graph(graph *Graph)
{
    int i;
    for(i = 0; i < MAX_SIZE; i++)
    {
        printf("Vertice %d: ", i);
        adj_list *current = Graph->vertices[i];
        while(current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

adj_list* create_adj_list(int item)
{
    adj_list *new_adj_list = (adj_list*)malloc(sizeof(adj_list));
    new_adj_list->data = item;
    new_adj_list->next = NULL;
    return new_adj_list;
}

void add_edge(graph *Graph, int vertex1, int vertex2)
{
    adj_list *vertex = create_adj_list(vertex2);
    vertex->next = Graph->vertices[vertex1];
    Graph->vertices[vertex1] = vertex;

    // Undirected graph. Edge to other direction as well.
    vertex = create_adj_list(vertex1);
    vertex->next = Graph->vertices[vertex2];
    Graph->vertices[vertex2] = vertex;
}

graph* create_graph()
{
    graph *Graph = (graph*)malloc(sizeof(graph));
    int i;
    for(i = 0; i < MAX_SIZE; i++)
    {
        Graph->vertices[i] = NULL;
        Graph->visited[i] = 0;
    }

    return Graph;
}

int main()
{
    int v, p, i, add1, add2, s, d;
    graph *grafo = create_graph();

    scanf("%d%d", &v, &p);

    for(i = 0; i < p; i++)
    {
        scanf("%d%d", &add1, &add2);
        add_edge(grafo, add1, add2);
    }

    scanf("%d%d", &s, &d);
    bfs(grafo, s, d);
}