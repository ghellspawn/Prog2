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

struct binary_tree* search_in_binary_tree(struct binary_tree *binary_tree, int item, int depth)
{
    depth++;

	if ((binary_tree == NULL)) 
	{
        printf("NAO ESTA NA ARVORE\n-1\n");
		return binary_tree;
	}
    else if((binary_tree->item == item))
    {
        printf("ESTA NA ARVORE\n%d\n", depth);
        return binary_tree;
    }
	else if (binary_tree->item > item) 
	{
		return search_in_binary_tree(binary_tree->left, item, depth);
	} 
	else 
	{
		return search_in_binary_tree(binary_tree->right, item, depth);
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

    int wanted;
    scanf("%d", &wanted);

    struct binary_tree *bt = NULL;
    int i = 0;

    bt = create_binary_tree_brackets(bt, stringTree, &i);
    search_in_binary_tree(bt, wanted, -1);
    
    return 0;
}