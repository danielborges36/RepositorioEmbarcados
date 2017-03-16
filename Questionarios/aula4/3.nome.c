#include <stdio.h>

int main(int argc, char **argv)
{
    char *nome, *idade, na[34], mensg[50];
    nome = argv[1];
    idade = argv[2];

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
