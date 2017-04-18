#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
	int i;
	pid_t filho[3];
	for(i=0; i<3; i++)
		filho[i] = fork();
	return 0;
}
