#include <stdio.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
    int tamanho;
    FILE *arquivo;
    if( !(arquivo = fopen(nome_arquivo,"r")) )
    {
        printf("Erro! Impossivel abrir o arquivo!\n");
        exit(1);
    }

    // movimenta a posição corrente de leitura no arquivo para o seu fim
    fseek(arquivo, 0, SEEK_END);
    // pega a posição corrente de leitura no arquivo
    tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
    int i=0;
    FILE *arquivo;
    if( !(arquivo = fopen(nome_arquivo,"r")) )
    {
        printf("Erro! Impossivel abrir o arquivo!\n");
        exit(1);
    }

    while( (conteudo[i]=fgetc(arquivo))!= EOF )
        i++;
    conteudo[i] = '\0';
}
