#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main()
{
        pid_t pid;
        pid = fork();
        if(pid ==  0){
                printf("I am the child \n");
                printf("PID:%d\n",getpid());
                printf("PPID:%d\n",getppid());
                
        }else if(pid>0){
                printf("I am the parent\n");
                printf("PID:%d\n",getpid());
                printf("PPID:%d\n",getppid());
        }else{
                printf("Error");
        }
        return 0;
}