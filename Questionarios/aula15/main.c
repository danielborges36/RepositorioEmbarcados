#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

int main(void)
{
	struct pollfd port5;
	pid_t pid;
	char i=1, buffer;
	int port4, pipe_d[2];
	int period=500000, btn_press;

	pipe(pipe_d);
	pid = fork();
    if(!pid)
    {
        system("echo 4       > /sys/class/gpio/export");
        system("echo in      > /sys/class/gpio/gpio4/direction");
        port4 = open("/sys/class/gpio/gpio4/value", O_WRONLY);

        while(1)
        {
            read(pipe_d[0], &period, sizeof(int));
            i = !i;
            buffer = '0'+i;
            write(port4, &buffer, sizeof(char));
            usleep(period);
        }
    }
    else
    {
        write(pipe_d[1], &period, sizeof(int));

        system("echo 5       > /sys/class/gpio/export");
        system("echo falling > /sys/class/gpio/gpio5/edge");
        system("echo in      > /sys/class/gpio/gpio5/direction");
        port5.fd = open("/sys/class/gpio/gpio5/value", O_RDONLY);
        if(port5.fd < 0)
        {
            puts("Erro abrindo /sys/class/gpio/gpio5/value");
            puts("Execute este programa como root.");
            return 1;
        }
        port5.events = POLLPRI | POLLERR;
        port5.revents = 0;

        while(1)
        {
            for(btn_press=0; btn_press<5; btn_press++)
            {
                read(port5.fd, &buffer, 1);
                poll(&port5, 1, -1);
                usleep(200000);
            }
            i++;
            if(i> 64)   i= 1;
            period = 500000/i;
            write(pipe_d[1], &period, sizeof(int));
        }
        close(port5.fd);
        system("echo 5 > /sys/class/gpio/unexport");
    }
}
