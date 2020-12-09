#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
void sighadnler(int signo)
{
    printf("signo = %d\n",signo);
}
int main()
{
    //int setitimer(int which, const struct itimerval *new_value,
    //                 struct itimerval *old_value);
    signal(SIGALRM,sighadnler);
    struct itimerval tm;
    tm.it_interval.tv_sec = 1;
    tm.it_interval.tv_usec = 0;
    tm.it_value.tv_sec = 3;
    tm.it_value.tv_sec = 0;

    setitimer(ITIMER_REAL,&tm,NULL);
    while(1) 
    {     
        sleep(1);
          
    }    
    return 0;
}
