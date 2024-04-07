//hello.c
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
int main(){
printf("hi\n");
fork();
printf("Hello\n");
return 0;
}
