#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int i;
	char *arg[] ={NULL,"-h",NULL};
	pid_t filho[argc];
	for(i=0; i<(argc-1); i++)
	{
		filho[i] = fork();
		if(filho[i]==0)
		{
            arg[0]=argv[i+1];
            execvp(arg[0],arg);
		}
	}
	return 0;
}
