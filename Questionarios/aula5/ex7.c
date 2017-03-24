#include <stdio.h>
#include "bib_arqs.c"

int strfind(char *string1, char *string2);

int main(int argc, char **argv)
{
    char *nome, *palavra;
    palavra = argv[1];
    nome = argv[2];
    int tamanho, i, results=0;

    tamanho = tam_arq_texto(nome)-1;
    char conteudo[tamanho];
    le_arq_texto(nome, conteudo);

    for(i=0; i<tamanho; i++)
    {
        if( strfind(conteudo+i, palavra) )
            results++;
    }

    printf("'%s' ocorre %d vezes no arquivo %s", palavra, results, nome);
}

int strfind(char *stringP, char *stringS)
{
    int i;

    for (i=0; stringS[i]; i++)
    {
        if(stringP[i] != stringS[i])
            return 0;
    }
    return 1;
}
