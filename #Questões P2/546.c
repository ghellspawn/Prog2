#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

struct binary_tree 
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
};

int is_bst_util(struct binary_tree* root, int min_value, int max_value)
{
    if(root == NULL)
    {
        return 1;
    }
    if(root->item > min_value && root->item < max_value && is_bst_util(root->left, min_value, root->item) && is_bst_util(root->right, root->item, max_value))
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
	if (input[(*i)++] == '(') // prestar atenção na incrementação
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
    char stringTree[9999];
    scanf(" %[^\n]s", stringTree);

    struct binary_tree *bt = NULL;
    int i = 0;

    bt = create_binary_tree_brackets(bt, stringTree, &i);

    int return_da_bst = is_bst_util(bt, INT_MIN, INT_MAX);

    if(return_da_bst == 1)
    {
        printf("VERDADEIRO\n");
    }
    else
    {
        printf("FALSO\n");
    }
    
    return 0;
}