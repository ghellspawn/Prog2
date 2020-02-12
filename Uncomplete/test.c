#include <stdio.h>
#include <stdlib.h>

#define UNVISITED_MAX -999
#define UNVISITED_MIN 999

typedef struct node
{
    int value, left, right;
} node;

void find_max_min(int max[], int min[], node t[], int data, int count)
{
    if(t[data].value > max[count])
    {
        max[count] = t[data].value;
    }

    if(t[data].value < min[count])
    {
        min[count] = t[data].value;
    }

    if(t[data].left != -1)
    {
        find_max_min(max, min, t, t[data].left, count + 1);
    }

    if(t[data].right != -1)
    {
        find_max_min(max, min, t, t[data].right, count + 1);
    }
}

void height(node t[], int data, int count, int *h)
{
    if(count > *h)
    {
        *h = count;
    }

    if(t[data].left != -1)
    {
        height(t, t[data].left, count + 1, h);
    }

    if(t[data].right != -1)
    {
        height(t, t[data].right, count + 1, h);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    node tree[n];

    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tree[i].value, &tree[i].left, &tree[i].right);
    }

    int h = 0;

    height(tree, 0, 1, &h);

    int max[h], min[h];

    for(i = 0; i < h; i++)
    {
        max[i] = UNVISITED_MAX;
        min[i] = UNVISITED_MIN;
    }

    find_max_min(max, min, tree, 0, 0);

    for(i = 0; i < h; i++)
    {
        printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, max[i], min[i]);
    }
    
    return 0;
}