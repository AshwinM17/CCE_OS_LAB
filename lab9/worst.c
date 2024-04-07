#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void worst_fit(int n,int m,int *holes,int *process){
	int i,j;
	int max,maxfit;
	for(i=0;i<m;i++){
		maxfit=INT_MIN;
		max=0;
		for(j=0;j<n;j++){
			if(process[i]<holes[j] && holes[j]-process[i]>maxfit){
				max=j;
				maxfit=holes[j]-process[i];
			}
		}
		if(maxfit!=INT_MAX){
			holes[max]-=process[i];
			printf("Process %d in hole %d\n",(i+1),(max+1));
		}
	}	
}

int main()
{
	int n,m,i;
	printf("Enter the number of holes\n");
	scanf("%d",&n);
	printf("Enter the number of process\n");
	scanf("%d",&m);
	int *holes=(int*)malloc(n*sizeof(int));
	printf("Enter the sizes of holes\n");
	for(i=0;i<n;i++){
		scanf("%d",&holes[i]);
	}
	int *process=(int*)malloc(m*sizeof(int));
	printf("Enter the sizes of process\n");
	for(i=0;i<m;i++){
		scanf("%d",&process[i]);
	}
	printf("Worst fit\n");
	worst_fit(n,m,holes,process);
}