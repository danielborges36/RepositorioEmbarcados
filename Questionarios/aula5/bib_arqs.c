#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
    int descrArquivo, tamanho;
	descrArquivo = open(nome_arquivo, O_RDONLY);
	if(descrArquivo==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
    // movimenta a posição corrente de leitura no arquivo para o seu fim
    lseek(descrArquivo, 0, SEEK_END);
    // pega a posição corrente de leitura no arquivo
    tamanho = tell(descrArquivo)-6;
	close(descrArquivo);
    return tamanho;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
    int i=0;
    int descrArquivo;
	descrArquivo = open(nome_arquivo, O_RDONLY);
	if(descrArquivo == -1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

    while( read(descrArquivo, conteudo+i, 1) != EOF)//conteudo[i]!= EOF )
        i++;
    conteudo[36] = '\0';
}
