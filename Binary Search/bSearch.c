#include <stdio.h>

void binarySearch(int array[], int size, int wanted, int i)
{
    int start, end, mid;

    start = 0;
    end = size - 1;

    while(start <= end)
    {
        mid = (start + end)/2;

        if(array[mid] == wanted)
        {
            printf("O numero foi achado depois %d busca(s)\n", i);
            return;
        }

        else if(wanted < array[mid])
        {
            end = mid - 1;
            i++;
        }

        else
        {
            start = mid + 1;
            i++;
        }
    }

    return;
}

void bubble(int array[], int i, int j, int n)
{
	if(j == n)
	{
		i = i+1;
		j = i+1;
	}
	if(i == n-1)
    {
        return;
    }

	if(array[i] > array[j])
	{
		int aux;
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	bubble(array, i, j+1, n);
}

int main()
{
    int size, wanted;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    printf("Digite o array: ");

    int array[size];
    
    int i;
    for(i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("O array é composto por: ");

    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    bubble(array, 0, 1, size);

    printf("O array ordenado fica: ");

    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
    
    printf("Qual será o número procurado?\n");

    scanf("%d", &wanted);

    binarySearch(array, size, wanted, 0);

    return 0;
}