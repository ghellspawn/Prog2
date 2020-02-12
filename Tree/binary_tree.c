#include <stdio.h>
#include <stdlib.h>

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

struct binary_tree* create_by_layers(struct binary_tree *binary_tree, int *array, int size, int i)
{
	if (i >= size) return NULL;
	else return create_binary_tree(array[i], create_by_layers(binary_tree, array, size, i*2), create_by_layers(binary_tree, array, size, (i*2)+1));
}

int is_leaf (struct binary_tree *binary_tree)
{
	return (binary_tree->left == NULL && binary_tree->right == NULL);
} 

int product (struct binary_tree *binary_tree)
{
	if (is_leaf(binary_tree)) return binary_tree->item;
	else return binary_tree->item * maximum(product(binary_tree->left),product(binary_tree->right));
}

struct binary_tree* search_in_binary_tree(struct binary_tree *binary_tree, int item)
{
	if ((binary_tree == NULL) || (binary_tree->item == item)) 
	{
		return binary_tree;
	} 
	else if (binary_tree->item > item) 
	{
		return search_in_binary_tree(binary_tree->left, item);
	} 
	else 
	{
		return search_in_binary_tree(binary_tree->right, item);
	}
}

int is_empty (struct binary_tree *binary_tree)
{
	if (binary_tree == NULL) return 1;
	else return 0;
}

void print_in_order(struct binary_tree *binary_tree)
{
	if (!is_empty(binary_tree)) 
	{
		print_in_order(binary_tree->left);
		printf("%d", binary_tree->item);
		print_in_order(binary_tree->right);
	}
}

void print_pre_order(struct binary_tree *binary_tree)
{
	if (!is_empty(binary_tree)) 
	{
		printf("%d", binary_tree->item);
		print_pre_order(binary_tree->left);
		print_pre_order(binary_tree->right);
	}
}

void print_post_order(struct binary_tree *binary_tree)
{
	if (!is_empty(binary_tree)) 
	{
		print_post_order(binary_tree->left);
		print_post_order(binary_tree->right);
		printf("%d", binary_tree->item);
	}
}

struct binary_tree* add_in_binary_tree(struct binary_tree *binary_tree, int item)
{
	if (binary_tree == NULL) 
	{
		binary_tree = create_binary_tree(item, NULL, NULL);
	} 
	else if (binary_tree->item > item)
	{
		binary_tree->left = add_in_binary_tree(binary_tree->left, item);
	} 
	else 
	{
		binary_tree->right = add_in_binary_tree(binary_tree->right, item);
	}
	return binary_tree;
}

int is_binary_tree (struct binary_tree *binary_tree)
{
	if (binary_tree != NULL)
	{
		if (binary_tree->left != NULL && binary_tree->right != NULL)
		{
			if (binary_tree->left->item > binary_tree->item || binary_tree->right->item < binary_tree->item)
			{
				return 0;
			}
		}
		return is_binary_tree(binary_tree->left) && is_binary_tree(binary_tree->right);
	}
	return 1;
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

int height = -1;

void belong_tree(struct binary_tree* binary_tree, int depth, int key)
{
	if (binary_tree == NULL) return;
	else 
	{
		if (binary_tree->item == key) {
			height = depth;
		}
		belong_tree(binary_tree->left, depth+1,key);
		belong_tree(binary_tree->right, depth+1,key);
	}
}