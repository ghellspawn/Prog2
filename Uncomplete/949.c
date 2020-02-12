#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree 
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
} bt;

int find_min(bt *binary_tree,  int level)
{
	if(binary_tree == NULL)
	{
		return 0;
	}

	if(level == 0)
	{
		return binary_tree->item;
	}

	int res = binary_tree->item;  
	int lres = find_min(binary_tree->left, level - 1);  
	int rres = find_min(binary_tree->right, level - 1);  

	if (lres < res)
	{
		res = lres;  
	}

	if (rres < res)
	{
		res = rres;
	}

	return res;
}

int find_max(bt *binary_tree,  int level)
{
	if(binary_tree == NULL)
	{
		return 0;
	}

	if(level == 0)
	{
		return binary_tree->item;
	}

	int res = binary_tree->item;  
	int lres = find_min(binary_tree->left, level - 1);  
	int rres = find_min(binary_tree->right, level - 1);  

	if (lres > res)
	{
		res = lres;  
	}

	if (rres > res)
	{
		res = rres;
	}

	return res;
}

int height(bt* binary_tree)  
{ 
   	if(binary_tree == NULL)
   	{
    	return 0; 
   	}
	else 
	{ 
		int lDepth = height(binary_tree->left); 
		int rDepth = height(binary_tree->right); 

		if (lDepth > rDepth)
		{
			return(lDepth+1); 
		}
		else
		{
			return(rDepth+1);
		} 
	}
}

bt* create_binary_tree(int item, bt *left, bt *right)
{
	bt*new_binary_tree = (bt*) malloc(sizeof(bt));
	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;
	return new_binary_tree;
}

bt* create_empty_binary_tree()
{
	return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);

    bt *new_bt = create_empty_binary_tree();
    int wheight, left_child, right_child;

    int i = 0;
    while(i < n)
    {
        scanf("%d%d%d", &wheight, &left_child, &right_child);

		bt *left = create_binary_tree(left_child, NULL, NULL);
		bt *right = create_binary_tree(right_child, NULL, NULL);

        new_bt = create_binary_tree(wheight, left, right);

        i++;
    }

	int level_max = height(new_bt);

	for(i = 0; i < level_max; i++)
	{
		int max = find_max(new_bt, i);
		int min = find_min(new_bt, i);

		printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, max, min);
	}
	
    return 0;
}