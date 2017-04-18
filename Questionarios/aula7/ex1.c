#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
	int descrArquivo, i;
	const char string[] = "Ola mundo!";

	descrArquivo = open("ola_mundo.txt", O_WRONLY|O_CREAT);
	if(descrArquivo==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

	for(i=0; string[i];i++)
		write(descrArquivo, string, strlen(string));

	close(descrArquivo);
	return 0;
}
