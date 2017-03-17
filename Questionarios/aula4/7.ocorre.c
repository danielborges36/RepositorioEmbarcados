#include <stdio.h>
#include <string.h>
#include "bib_arqs.c"

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
        if( !strcmp(palavra,conteudo) )
            results++;
        conteudo = conteudo+1;
    }

    printf("'%s' ocorre %d vezes no arquivo %s", palavra, results, nome);
}
