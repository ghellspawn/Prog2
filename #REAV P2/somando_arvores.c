#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    int item;
    int height;
    binary_tree *left, *right;
};

int is_empty(binary_tree *bt) {
    return bt == NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *bt = (binary_tree*) malloc(sizeof(binary_tree));
    bt->item = item;
    bt->left = bt->right = NULL;
    return bt;
}

binary_tree* construct_binary_tree(char *str, int *pos) {

    binary_tree *bt = NULL; //ponteiro para a arvore
    int i = 0;
    int numInt;       //numero do no (inteiro)
    char numStr[50];  //numero do no (string)

    while(str[*pos] == '(') { //ignora os parenteses abrindo
        *pos += 1;
    }

    if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
        *pos += 1;         // pois o ponteiro eh nulo
        return bt;
    }
    else {
        while(str[*pos] != '(') {    //se for diferente de abre parenteses
            numStr[i++] = str[*pos]; //le o numero string
            *pos += 1;
        }
        numStr[i] = '\0'; //finalizando a string com '/0'
        numInt = atoi(numStr); //converte o numero string para inteiro

        bt = create_binary_tree(numInt, NULL, NULL); //cria um no com o numero inteiro
        bt->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
        bt->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
    }
    *pos += 1;
    return bt; //retorna o ponteiro para a arvore
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

void print_pre_order(binary_tree *bt) {
    if (!is_empty(bt)) {
        printf("(");
        printf("%d ", bt->item);

        if (bt->left == NULL) {
            printf("()");
        } else {
            print_pre_order(bt->left);
        } if (bt->right == NULL) {
            printf("()");
        } else {
            print_pre_order(bt->right);
        }
        printf(")");
    }
}

int main()
{
    while(1)
    {
        struct binary_tree *bt = NULL;

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

            if(data != ' ' && data != '\n' && data != '\0')
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

        bt = construct_binary_tree(stringArv, &k);

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