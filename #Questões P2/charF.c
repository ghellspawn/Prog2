#include <stdio.h>
#include <string.h>

void find_frequency(char s[], int count[]) 
{
   int c = 0;
   
   while (s[c] != '\0') // '\0' significa final de string
   {
        if (s[c] >= 'a' && s[c] <= 'z' ) //vai de A até Z
        {
            count[s[c]-'a']++;
        }
        
        c++;
   }
}

int main()
{
    char string[256]; //string a ser analisada
    int c, count[26] = {0}; //componentes da tabela do print

    printf("Escreva uma string:\n");
    scanf(" %[^\n]s", string);

    find_frequency(string, count);

    printf("Contagem de Caracteres\n");

    for(c = 0; c < 26; c++)
    {
        if(count[c] != 0)
        {
            printf("%c \t %d\n", c + 'a', count[c]);
        }
    }

    return 0;
}