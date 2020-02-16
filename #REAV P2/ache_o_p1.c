#include <stdio.h>
#include <stdlib.h>

void run_tree(int array[], int height, int *productory, int i, int j, int res, int size)
{
    if(j == height)
    {
        if(*productory < res)
        {
            *productory = res;
        }

        return;
    }

    if(i < size)
    {
        res *= array[i];
    }

    run_tree(array, height, productory, 2 * i, j + 1, res, size);
    run_tree(array, height, productory, (2 * i) + 1, j + 1, res, size);
}

int main()
{
    int h;

    scanf("%d", &h);

    int array[999], start = 1, productory = 0;

    while(scanf("%d", &array[start]) != EOF)
    {
        start++;
    }

    run_tree(array, h, &productory, 1, 0, 1, start);
    
    printf("%d\n", productory);
}