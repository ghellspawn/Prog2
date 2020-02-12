#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(int size, char *string, int entry, int i, int j)
{
    if(i == size)
    {
        return j;
    }

    // A = 65 | A - A = 0 | B - A = 1 ...
    j += (string[i] - 'A') + entry + i;

    i++;
    hash(size, string, entry, i, j);
}

int main()
{
    int n, answer;
    int i, j;
    char string[50];
    int entry = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        int n2;
        scanf("%d", &n2);

        for(j = 0; j < n2; j++)
        {
            scanf(" %[^\n]s", string);
            int size = strlen(string);

            answer += hash(size, string, entry, 0, 0);
            entry++;
        }

        printf("%d\n", answer);

        answer = 0; entry = 0; 
    }

    return 0;
}