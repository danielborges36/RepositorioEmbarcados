#include <stdio.h>
#include "bib_arqs.c"

int main(int argc, char **argv)
{
    char *nome;
    nome = argv[1];
    int tamanho, i;

    tamanho = tam_arq_texto(nome)-1;
    char conteudo[tamanho];
    le_arq_texto(nome, conteudo);

    for(i=0; i<tamanho; i++)
        putchar(conteudo[i]);
}
