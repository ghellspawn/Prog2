#include <stdio.h>

int main()
{
    int i, array[256];

    for(i = 0; i < 256; i++)
    {
        if(scanf("%d", &array[i]) == 'EOF')
        {
            break;
        }
        else
        {
            continue;
        }
    }
}