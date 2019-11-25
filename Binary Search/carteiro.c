#include <stdio.h>
#include <stdlib.h>

int bSearch(int n, int m, int *casa1, int wanted, int previous, int *mid)
{
    int start, end, i;

    start = 0;
    end = n - 1;

    while(start <= end)
    {
        *mid = (start + end)/2;

        if(casa1[*mid] == wanted)
        {   
            return abs(*mid - previous);
        }

        else if(wanted < casa1[*mid])
        {
            end = *mid - 1;
        }

        else
        {
            start = *mid + 1;
        }
    }

}

void read()
{
    int n, m, i;
    scanf("%d%d", &n, &m);
    
    int casa1[n]; //estritamente crescentes
    for(i = 0; i < n; i++)
    {
        scanf("%d", &casa1[i]);
    }
    

    int casa2[m];
    for(i = 0; i < m; i++)
    {
        scanf("%d", &casa2[i]);
    }

    int previous = 0, dist = 0;

    for(i = 0; i <m; i++) 
        {
            int mid = 0;
            dist += bSearch(n, m, casa1, casa2[i], previous, &mid);
            previous = mid;
        }

    printf("%d\n", dist);

}

int main()
{
    read();

    return 0;
}