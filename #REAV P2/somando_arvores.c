#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct binary_tree 
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
};

struct binary_tree* create_empty_binary_tree()
{
	return NULL;
}

struct binary_tree* create_binary_tree (int item, struct binary_tree *left, struct binary_tree *right)
{
	struct binary_tree *new_binary_tree = (struct binary_tree*) malloc(sizeof(struct binary_tree));
	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;
	return new_binary_tree;
}

int is_empty (struct binary_tree *binary_tree)
{
	if (binary_tree == NULL) return 1;
	else return 0;
}

struct binary_tree *check_sum(struct binary_tree *bt, int wanted, int sum, int *flag)
{
    if(bt == NULL)
    {
        return bt;
    }

    sum += bt->item;

    if(bt->left == NULL && bt->right == NULL)
    {
        if(wanted == sum)
        {
            *flag = 1; //achei
        }
    }

    check_sum(bt->left, wanted, sum, flag);
    check_sum(bt->right, wanted, sum, flag);
}

void print_pre_order_brackets(struct binary_tree *binary_tree)
{
	printf(" (");
	if (!is_empty(binary_tree)) 
	{
		if (binary_tree != NULL) printf(" %d ", binary_tree->item);
		else printf(" ()");
		if (binary_tree->left == NULL) printf(" ()");
		else print_pre_order_brackets(binary_tree->left);
		printf(" ");
		if (binary_tree->right == NULL) printf(" ()");
	 	else print_pre_order_brackets(binary_tree->right);
	}
	printf(" )");
}

struct binary_tree* create_binary_tree_brackets(struct binary_tree *binary_tree, char *input, int *i)
{
	if (input[(*i)++] == '(')
	{
		if (input[*i] == ')') {
			(*i)++;
			return NULL;	
		} 
		else
		{
			int j = 0, value = 0, node[100];
			while (input[(*i)] != '(')
			{
				node[j] = input[*i];
				j++;
				(*i)++;
			}
			int size = j;
			j = 0;
			while (j != size) 
			{
				value += pow(10, size - j - 1) * (node[j] - '0');
				j++;
			}
			binary_tree = create_binary_tree(value, NULL, NULL);
			binary_tree->left = create_binary_tree_brackets(binary_tree->left, input, i);
			binary_tree->right = create_binary_tree_brackets(binary_tree->right, input, i);
		}
		(*i)++;
		return binary_tree;
	}
}

int main()
{
    while(1)
    {
        struct binary_tree *bt = create_empty_binary_tree();

        char stringArv[99999] = {0}, data;
        int i = 0, j = 0, k = 0, flag = 0, item;

        scanf("%d", &item);

        if(item == -1000)
        {
            break;
        }

        while(1)
        {
            scanf(" %c", &data);

            if(data != ' ' && data != '\n')
            {
                stringArv[i] = data;
                i++;

                if(data == '(')
                {
                    j++;
                }
                else if(data == ')')
                {
                    j--;
                }

            }

            if(j == 0)
            {
                break;
            }
        }

        stringArv[i] = '\0';

        bt = create_binary_tree_brackets(bt, stringArv, &k);
        //print_pre_order_brackets(bt);

        check_sum(bt, item, 0, &flag);

        if(flag == 1)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
        
    }


    return 0;
}