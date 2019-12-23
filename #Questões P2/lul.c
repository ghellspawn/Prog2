#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct binary_tree{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->item = item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}
void search(binary_tree *arvore, int item, int *prof, int *achou)
{
    (*prof)++;

    if(arvore == NULL) 
    {
        return;
    }
    else if(arvore->item == item)
    {
        *achou = 1;
        return;
    }
    else if (arvore->item > item) 
    {
        search(arvore->left, item, prof, achou);
    } 
    else 
    {
        search(arvore->right, item, prof, achou);
    }
}

binary_tree *loop(binary_tree *arvore, int *i, char str[], int tam) {
    if(str[*i] == '('){
        if(str[*i + 1] == ')') {
            *i += 2;
            return NULL;
        } else {
            (*i)++;
            //printf("*i = %d\n", *i);
            int value = 0, j = 0;
            while(str[*i + j] != '(') {
                j++; // vai guardar a quantidade de numeros que vao ser encontrados.
            }
            //printf("char_1: %c\n", str[*i]);
            int a = j;
            j = 0;
            while(j != a) {
                //printf("char: %c\n", str[*i]);
                int b = str[*i] - '0'; // transforma um char em inteiro.
                value += pow(10,a - j - 1) * b;
                //printf("expressao: %lf, j = %d, a = %d, str = %d\n", pow(10,a - j - 1) * b, j, a, b);
                j++;
                (*i)++;
            }
            //printf("x = %d e *i = %d\n", x, *i);
            arvore = create_binary_tree(value, NULL, NULL);
            arvore->left = loop(arvore->left, i, str, tam);
            arvore->right = loop(arvore->right, i, str, tam);
        }
    }
    (*i)++;
    return arvore;
}

int main() 
{
    binary_tree *arvore = NULL;

    char str[99999];
    scanf(" %[^\n]s", str);
    int tam = strlen(str);

    int quero, prof = -1, achou = 0;
    scanf("%d", &quero); 

    int i = 0;
    arvore = loop(arvore, &i, str, tam);

    search(arvore, quero, &prof, &achou);

    if(achou == 1) 
    {
        printf("ESTA NA ARVORE\n%d\n", prof);
    } 
    else
    {
        printf("NAO ESTA NA ARVORE\n-1\n");
    }
    

    return 0;
}