#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<syslog.h>

int main()
{
    __pid_t pid = fork();
    if(pid==0)
    {
        chdir("/");
        setsid();
        printf("starting my deamon\n");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("my deamon ", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE,"deamon started");
        usleep(3000000);
        syslog(LOG_NOTICE, "doing some work....");
        usleep(3000000);
        syslog(LOG_NOTICE,"deamon finished");
    }
    else
    {
        printf("deamon PID %d\n", pid);
    }
    return 0;
}
