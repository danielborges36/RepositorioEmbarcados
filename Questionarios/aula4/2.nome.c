#include <stdio.h>

int main(int argc, char **argv)
{
    char nome[30], idade[3], na[34], mensg[50];
    printf("\nDigite o seu nome: ");
    scanf("%s",&nome);
    printf("Digite a sua idade: ");
    scanf("%s",&idade);

    sprintf(na,"%s.txt", nome);
    FILE *arquivo;
    if( !(arquivo = fopen(na,"w")) )
    {
        printf("Erro! Impossivel abrir o arquivo!\n");
        exit(1);
    }

    sprintf(mensg,"Nome: %s\nIdade: %s anos\n", nome, idade);
    fprintf(arquivo, mensg);
    fclose(arquivo);
}
