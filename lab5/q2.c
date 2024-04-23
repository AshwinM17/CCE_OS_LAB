#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *strings[5];
    char *string_cpy[5];
    char temp[100];
    int i, j;
    pid_t pid;
    int status;
    printf("Enter your strings");
    for (i = 0; i < 5; i++)
    {
        strings[i] = malloc(100 * sizeof(char));
        string_cpy[i]=malloc(100 * sizeof(char));
        scanf("%s", strings[i]);
        strcpy(string_cpy[i],strings[i]);
    }
    pid=fork();
    if (pid == 0)
    {
        printf("Child Process\n");
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5 - i -1; j++)
            {
                if (strcmp(strings[j], strings[j + 1]) > 0)
                {
                    strcpy(temp, strings[j]);
                    strcpy(strings[j], strings[j + 1]);
                    strcpy(strings[j + 1], temp);
                }
            }
        }
        for(i=0;i<5;i++){
            printf("Child: %s \n",strings[i]);
        }
        
        printf("\n");
        exit(21);
    }else if(pid>0){
        wait(&status);
        printf("Parent Process\n");
      	for(int i=0;i<5;i++){
      		
                printf("Parent: %s \n",string_cpy[i]);
        }
        printf("%d",WEXITSTATUS(status));
    }else{
        printf("Error");
    }
}
