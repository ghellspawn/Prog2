#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define MAX 255
 
int top = -1;
int stack[MAX];
 
void push(char item)
{
	if(top == (MAX - 1))
	{
		printf("Stack overflow\n");
		return;
	}

    top++;
    stack[top] = item;
}
 
char pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }

    return (stack[top--]);
}
 
int match_paranthesis(char a, char b)
{
	if(a == '[' && b == ']')
	{
		return 1;
	}
	else if(a == '(' && b == ')')
	{
		return 1;
	}

	return 0;
}
 
int check_paranthesis(char expression[])
{
	int count;
	char temp;
	for(count = 0; count < strlen(expression); count++)
	{
		if(expression[count] == '(' || expression[count] == '[')
		{
			push(expression[count]);
		}

		if(expression[count] == ')' || expression[count] == ']')
		{
			if(top == -1)
			{
				return 0;
			}
			else
			{
				temp = pop();

				if(!match_paranthesis(temp, expression[count]))
				{
					return 0;
				}
			}
		}
	}

	if(top == -1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int main()
{
	int times;
	scanf("%d", &times);
	getchar();

	int cont = 0;

	while(cont < times)
	{
		char expression[MAX];
		int validity;

		gets(expression);
		top = -1;

		validity = check_paranthesis(expression);

		if(validity == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		cont++;
	}

    return 0;
}