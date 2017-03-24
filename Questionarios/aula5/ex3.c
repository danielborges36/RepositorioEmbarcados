#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int descrArquivo;
    char *nome, *idade, na[34], string[50];
    nome = argv[1];
    idade = argv[2];

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
