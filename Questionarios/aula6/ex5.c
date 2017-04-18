#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/*Neste caso, cada processo enxergou um valor dependendo de quanto v_global do processo pai possuia quando chamava o filho*/

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
    v_global++;
    printf("ID do processo que executou esta funcao = %d\n", id_atual);
    printf("v_global = %d\n", v_global);
}

int main(int argc, const char *argv[])
{
	int i;
	pid_t filho[3];
	for(i=0; i<(3); i++)
	{
		filho[i] = fork();
		if(!filho[i])
		{
            Incrementa_Variavel_Global(getpid());
            exit(0);
		}
		Incrementa_Variavel_Global(getpid());
	}
	return 0;
}
