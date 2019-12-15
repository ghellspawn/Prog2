#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct adj_list
{
    int data;
    struct adj_list *next;
} adj_list;

typedef struct graph
{
    adj_list **vertices;
    short *visited;
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

typedef struct dist
{
    int distance;
    int predecessor;
}dist;

dist *dist_array(int v)
{
    dist *array = (dist*)malloc(sizeof(dist)*v);
    int i;

    for(i = 0; i < v; i++)
    {
        array[i].distance = -9999;
        array[i].predecessor = -1;
    }

    return array;
}


// --------------------------------------------------  QUEUE -----------------------------

NODE *insert_order(NODE *head, int item) 
{
    NODE *new_node = create_node(item);
    NODE *current = head;
    NODE *previous = NULL;

    if (is_empty_node(head)) 
    {
        return new_node;
    } 
    else if (head->item <= item) 
    {
        new_node->next = head;
        head->previous = new_node;
        return new_node;
    }
    while (current != NULL && current->item > item) 
    {
        previous = current;
        current = current->next;
    }
    if (previous->next == NULL) 
    {
        previous->next = new_node;
        new_node->previous = previous;
    } else 
    {
        previous->next = new_node;
        new_node->next = current;
        new_node->previous = previous;
    }
    return head;
}

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

dist *add_dist_array(dist *dist_array, int key, int distance, int predecessor) 
{
    dist_array[key].distance = distance;
    dist_array[key].predecessor = predecessor;
    return dist_array;
}

void bfs(graph *Grafo, int source, dist *dist_array)
{
    printf("Iniciando busca em largura a partir de %d\n", source);
    queue *queue = create_queue();
    int dequeued;

    adj_list *adj_list = Grafo->vertices[source];
    Grafo->visited[source] = 1;
    dist_array[source].distance = 0;
    dist_array[source].predecessor = -1;
    
    enqueue(queue, source);

    while(!is_empty(queue))
    {
        dequeued = dequeue(queue);
        adj_list = Grafo->vertices[dequeued];
        while(adj_list != NULL)
        {
            if(!Grafo->visited[adj_list->data])
            {
                dist_array[adj_list->data].distance = dist_array[dequeued].distance + 1;

                printf("Iniciando busca em largura a partir de %d\n", adj_list->data);
                printf("%d\n", adj_list->data);

                Grafo->visited[adj_list->data] = 1;

                enqueue(queue, adj_list->data);
                dist_array = add_dist_array(dist_array, adj_list->data, dist_array[adj_list->data].distance, dequeued);
            }

            adj_list = adj_list->next;
        }
    }
    printf("\n");
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

void print_graph(graph *Graph, int v)
{
    int i;
    for(i = 0; i < v; i++)
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

graph* create_graph(int v)
{
    graph *grafo = (graph*)malloc(sizeof(graph));               // Alocando o tamanho de graph     |                     |
    grafo->vertices = (adj_list**)malloc(sizeof(adj_list)*v);    // Alocando o tamanho de vertices  | Atenção pros tipos! |
    grafo->visited = (short*)malloc(sizeof(short)*v);           // Alocando o tamanho de visited   |                     |

    int i;
    for(i = 0; i < v; i++)
    {
        grafo->vertices[i] = NULL;
        grafo->visited[i] = 0;
    }

    return grafo;
}

int main()
{
    int v, a, t;
    scanf("%d%d%d", &v, &a, &t);
    
    graph *grafo = create_graph(v); // Inicializei o grafo
    NODE *array[a]; // Criei uma lista com o tamanho de arestas
    dist *d_array = dist_array(v); // Estartar o arrive e departure

    int arrive, departure, i;

    for (i = 0; i < a; i++) 
    {
        array[i] = NULL;
    }

    for(i = 0; i < a; i++)
    {
        scanf("%d%d", &arrive, &departure);                             // Aqui eu faço, a partir das arestas,
        array[arrive] = insert_in_order(array[arrive], departure);      // os pares de "viagem" e insiro eles numa lista.
    }

    for(i = 0; i < a; i++)
    {
        while(array[i] != NULL)
        {
            add_edge(grafo, i, array[i]->item);
            array[i] = array[i]->next;
        }
    }

    int j;
    for(j = 0; j < t; j++)
    {
        scanf("%d%d", &arrive, &departure);
        printf("--------\n\n");
        printf("Caso de Teste #%d - BFS(%d)\n\n", j + 1, arrive);

        for(i = 0; i < v; i++)
        {
            grafo->visited[i] = 0;  // Zero tudo do grafo
        }

        bfs();
    }
}