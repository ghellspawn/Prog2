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

void selectionSort(int *array, int n, int i)
{
    int iMin, j;

    for(i = 0; i < n - 1; i++)
    {
        iMin = i;

        for (j = i + 1; j < n - 1; j++)
        {
            if(array[j] < array[iMin])
            {
                iMin = j; //atualiza o index com o menor elemento do array.
            }
        }
        
        int temp = array[i];
        array[i] = array[iMin];
        array[iMin] = temp;
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

    selectionSort(array, n, 0);
}

int main()
{
    read();
}

//O Selection sort armazena o menor número do array e faz a troca.