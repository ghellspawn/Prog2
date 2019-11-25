#include <stdio.h>
#include <limits.h>

void merge (int a[] , int start , int mid , int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int i , j  , k , L[n1 + 1] , R[n2 + 1];    

    for (int i = 1 ; i <= n1 ; i++)
    {
        L[i] = a[start + i - 1];
    }

    for (int j = 1 ; j <= n1 ; j++)
    {
        R[j] = a[mid + j];
    }

    L[n1 + 1] = INT_MIN;
    R[n2 + 1] = INT_MIN;

    i = 1 , j = 1 ;

    for (k = start; k <= end; k++)
    {
        if (L[i] > R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        for (i = start; i < end; i++) printf("%d%c", a[i], (i < end - 1) ? ' ' : '\n');
    }
}
void merge_sort(int a[], int start , int end)
{
    int mid;

    if (start < end)
    {
        mid = (start + end) / 2 ;
        merge_sort(a, start , mid);
        merge_sort(a, mid + 1 , end);
        merge(a , start , mid, end);
    }
}
int main ()
{
	int n , i ;
	scanf("%d", &n);
	int a[n] ;

	for (i = 0 ; i < n ; i++) scanf("%d", &a[i]); 

	merge_sort(a , 0 , n - 1); 

	for (i = 0 ; i < n ; i++) printf("%d\n", a[i]);

	return 0 ;
}