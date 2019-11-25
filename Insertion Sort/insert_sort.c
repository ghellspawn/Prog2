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

void insertionSort(int *array, int n, int i)
{
    for(i = 1; i < n; i++)
    {
        int value = array[i];
        int hole = i;

        while (hole > 0 && array[hole - 1] > value)
        {
            array[hole] = array[hole - 1];
            hole = hole - 1;
        }

        array[hole] = value;
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

    insertionSort(array, n, 0);
}

int main()
{
    read();
}

//O Insection sort começa a trabalhar com o segundo valor do vetor e vai 
//jogando ele para a esquerda (início do vetor) até ordena-lo.