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

void search(struct binary_tree **wanted, struct binary_tree *second)
{
    if(second == NULL)
    {
        return;
    }

    if(second->item == (*wanted)->item)
    {
        (*wanted) = second;
        return;
    }

    search(wanted, second->left);
    search(wanted, second->right);
}

int is_leaf (struct binary_tree *binary_tree)
{
	return (binary_tree->left == NULL && binary_tree->right == NULL);
}

struct binary_tree* cocatenate(struct binary_tree *first, struct binary_tree *second)
{
    if(is_leaf(first))
    {
        search(&first, second);
    }
	cocatenate(first->left, second);
	cocatenate(first->right, second);
}

struct binary_tree* create_binary_tree (int item, struct binary_tree *left, struct binary_tree *right)
{
	struct binary_tree *new_binary_tree = (struct binary_tree*) malloc(sizeof(struct binary_tree));

	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;

	return new_binary_tree;
}

struct binary_tree* create_binary_tree_brackets (struct binary_tree *binary_tree, char *input, int *i)
{
	if (input[(*i)++] == '(') // prestar aten��o na incrementa��o
	{
		if (input[*i] == ')') 
        {
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
    char stop[2] = {'(', ')'};

    while(1)
    {
        int i, j, k;

        struct binary_tree *arrayTree[9999];

        for(i = 0; i < 9999; i++)
        {
            char stringTree[9999];
            scanf(" %[^\n]s", stringTree);

            if(strcmp(stop, stringTree) == 0)
            {
                for(j = 1; j < 9999; j++)
                {
                    cocatenate(arrayTree[j - 1], arrayTree[j]);
                }

                break;
            }
            else
            {
                struct binary_tree *bt = NULL;
                int i = 0;

                bt = create_binary_tree_brackets(bt, stringTree, &i);
                arrayTree[i] = bt;
            }
        }

    }
    
    return 0;
}