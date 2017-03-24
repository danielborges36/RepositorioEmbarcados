#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int descrArquivo;
    char nome[30], idade[4], na[34], string[50];

    printf("\nDigite o seu nome: ");
    scanf("%s",nome);
    printf("Digite a sua idade: ");
    scanf("%s",idade);

    sprintf(na,"%s.txt", nome);
	descrArquivo = open(na, O_WRONLY|O_CREAT);
	if(descrArquivo==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

    sprintf(string,"Nome: %s\nIdade: %s anos\n", nome, idade);
    write(descrArquivo, string, strlen(string));

	close(descrArquivo);
	return 0;
}
