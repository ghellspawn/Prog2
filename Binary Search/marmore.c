#include <stdio.h>

void binarySearch(int array[], int size, int wanted_q[], int q, int count)
{
    int start, end, mid, i;
    int flag;

    start = 0;
    end = size - 1;

    printf("Size: %d, Start = %d, End = %d, Mid = %d\n", size, start, end, mid);

    for(i = 0; i < q; i++)
    {
        flag = 0;

        while(start <= mid)
        {
            printf("CASE #%d:\n", i + 1);

            mid = (start + end)/2;

            if(array[mid] == wanted_q[i])
            {
                printf("%d found at %d\n", wanted_q[i], i);
                flag = 1;
                break;
            }

            else if(wanted_q[i] < array[mid])
            {
                end = mid - 1;
                count++;
            }

            else
            {
                start = mid + 1;
                count++;
            }

        }

        if(flag == 0)
        {
            printf("%d not found\n", wanted_q[i]);
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
    int size_n, q;

    scanf("%d %d", &size_n, &q); //leio o tamanho do array e o qtd de numeros procurados

    int array[size_n];

    int i;
    for(i = 0; i < size_n; i++)
    {
        scanf("%d", &array[i]); //leio o array
    }

    bubble(array, 0, 1, size_n); //ordeno o array

    int wanted_q[q]; //numeros a serem procurados

    for(i = 0; i < q; i++)
    {
        scanf("%d", &wanted_q[i]); //leio os numeros a serem procurados
    }

    for(i = 0; i < size_n; i++)
    {
        printf("Normal: %d\n", array[i]);
    }

    for(i = 0; i < q; i++)
    {
        printf("Wanted: %d\n", wanted_q[i]);
    }

    binarySearch(array, size_n, wanted_q, q, 0);

    return 0;
}