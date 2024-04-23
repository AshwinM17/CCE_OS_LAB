#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct{
	int arrival_time;
	int burst_time;
	int pid;
	bool completed;
}proc;

int main(){
	int time=0;
	int waiting_time[4];
	proc process[3];
	int i,j;
	for(i=0;i<3;i++){
		printf("Enter the process burst time and id");
		scanf("%d",&process[i].burst_time);
		scanf("%d",&process[i].pid);
		process[i].completed=false;
		process[i].arrival_time=0;
	}
	for(i=0;i<3;i++){
		int minpid=INT_MAX;
		int min;
		for(j=0;j<3;j++){
			if(!process[j].completed && process[j].pid < minpid){
				min =j;
				minpid=process[j].pid;
			}
		}
		process[min].completed=true;
		time=time + process[min].burst_time;
		waiting_time[min]=time-process[min].burst_time-process[min].arrival_time;
		printf("Process %d completed at %d\n",process[min].pid,time);
		printf("Waiting time %d\n\n",waiting_time[min]);
	}
	float avg=0;
	for(i=0;i<3;i++){
		avg+=waiting_time[i];
	}
	avg=avg/3;
	printf("Average waiting time:%f\n",avg);
	return 0;
}
