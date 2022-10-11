//64050149 ปัณฑ์ตะวัน บัวสังข์
/* 
Q1 เขียน Outputของ line 13 
 20! = 2432902008176640000
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//Q2
void mySIGhandler(int sig) 
{
	signal(SIGALRM,SIG_IGN);
}
int main(void)
{
    signal(SIGALRM,mySIGhandler);
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("child created\n");
        while (1);
        printf("this line should not be show\n");
        exit(0);
    }
    else
    {
        printf("Parent wait for sending SIGALRM\n");
        sleep(4);
        printf("Parent sending SIGALRM\n");
        kill(getpid(),SIGALRM);
    }
    printf("child has been killed\n");
    return 0;
}
