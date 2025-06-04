#include <stdio.h>
#include <locale.h>
typedef struct pessoa
{
    char nome[28];
    int idade;
    
}pessoa;


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i;
    pessoa cd_pessoa[2];

    for ( i = 0; i < 2; i++)
    {
        printf("Nome da %d pessoa:", i+1);
        scanf("%s", cd_pessoa[i].nome);
        printf("Qual é a Idade:");
        scanf("%d", &cd_pessoa[i].idade);
    }
    
    for (i = 0; i < 2; i++)
    {
        printf("Nome:%s\nIdade:%d", cd_pessoa[i].nome, cd_pessoa[i].idade);
    }
    


    return 0;
}
