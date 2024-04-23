#include <stdio.h>
#include <unistd.h>
int main(char * f1,char * f2)
{
	execl("/usr/bin/cp /usr/share/man/man1/cp.1.gz","cp"," q1.c ","test",NULL);
}
