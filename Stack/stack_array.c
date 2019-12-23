// Stack - Array based implementation.
#include <stdio.h>
#define MAX_SIZE 101

int a[MAX_SIZE];
int Top = -1;

void push(int x)
{
    if(Top == MAX_SIZE -1)
    {
        printf("Error: Stack overflow.\n");
        return;
    }

    Top++;
    a[Top] = x;
}

void pop()
{
    if(Top == -1)
    {
        printf("Error: No element to pop\n");
        return;
    }

    Top--;
}

int top()
{
    return a[Top];
}

int main()
{


    return 0;
}