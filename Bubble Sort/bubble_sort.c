#include <stdio.h>

void print(int n, int *array, int i)
{
    printf("O array ordenado ficou: \n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return;
}

void bubbleSort(int *array, int n, int i)
{
    int j;

    for (j = n - 1; j >= 0; j--) 
    {
        for (i = 0; i < j; i++) 
        {
            if(array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    print(n, array, 0);
}

void read()
{
    int n;

    printf("Digite o tamanho do array: \n");
    scanf("%d", &n);

    int array[n], i;

    printf("Digite o array: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, n, 0);
}

int main()
{
    read();
}

//O Bubble sort ele "agarra" o maior número do array e leva até o final,
//em prol de ordena-lo todo.