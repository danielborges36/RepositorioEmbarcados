#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
	int i;
	pid_t filho[argc];
	for(i=0; i<argc; i++)
	{
		filho[i] = fork();
		if(!filho[i])
		{
            execvp(argv[i+1],NULL);
            exit(0);
		}
	}
	return 0;
}
