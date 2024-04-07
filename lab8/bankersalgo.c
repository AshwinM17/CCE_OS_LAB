#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checksafety(bool *completed,int *available,int** need,int** allocation,int m,int n)
{
	bool eligible;	
	bool safe=true;
	int i,j;
	int completed_no=0;
	while(safe && completed_no<m){
		//printf("Safe");
		safe = false;
		for(i=0;i<m;i++){
            		if(!completed[i])
            		{
                		eligible=true;
   		             	for(j=0;j<n;j++)
   		             	{
        	            		if(available[j]<need[i][j])
        	            		{
        	                		eligible=false;
        	                		break;
        	           		}
        	        	}
        	        	
        	        	if(eligible)
        	        	{
        	            		printf("Process %d is executing\n",i);
        	            		for(j=0;j<m;j++)
        	            		{ 
        	          		      	available[j]+=allocation[i][j];
        	            		}
        	          		completed[i]=true;
        	          	  	completed_no++;
        	          	  	safe=true;
                		}	
            		}	
		}
		
	}
	return safe;
}

int main()
{
    //input the resources and processes
	int m,n,i,j;
	printf("Enter the number of processes:");
	scanf("%d",&m);
	printf("Enter the number of resources:");
	scanf("%d",&n);

	int *available = (int*)malloc(n*sizeof(int));
	bool *completed= (bool*)malloc(m*sizeof(bool));
	int** max = (int**)malloc(m * sizeof(int*));
	int** allocation = (int**)malloc(m * sizeof(int*));
	int** need = (int**)malloc(m * sizeof(int*));	
    	for (i = 0; i < m; i++){
		max[i] = (int*)malloc(n * sizeof(int));
		allocation[i] = (int*)malloc(n * sizeof(int));
		need[i] = (int*)malloc(n * sizeof(int));		
	}
	//creating copies of the structures for resource request algorithm
	int *cpyavailable = (int*)malloc(n*sizeof(int));
	bool *cpycompleted= (bool*)malloc(m*sizeof(bool));
	int** cpymax = (int**)malloc(m * sizeof(int*));
	int** cpyallocation = (int**)malloc(m * sizeof(int*));
	int** cpyneed = (int**)malloc(m * sizeof(int*));	
    	for (i = 0; i < m; i++){
		cpymax[i] = (int*)malloc(n * sizeof(int));
		cpyallocation[i] = (int*)malloc(n * sizeof(int));
		cpyneed[i] = (int*)malloc(n * sizeof(int));		
	}
    
    printf("Enter the available resources:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &available[i]);
        cpyavailable[i]=available[i];
    }

    printf("Enter the maximum resources each process can claim:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
            cpymax[i][j]=max[i][j];
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
            cpyallocation[i][j]=allocation[i][j];
            cpyneed[i][j]=need[i][j];
        }
        completed[i] = false;
        cpycompleted[i] = false;
    }
    
    bool safe=checksafety(completed,available,need,allocation,m,n);

	if(safe){
	printf("Processes are in safe state\n");
	printf("Resource Request Algorithm\n");
	printf("Enter the process index which is requesting:\n");
	int reqproc;
	scanf("%d",&reqproc);
	printf("Enter the  index of the type of resources;\n");
	int reqres;
	scanf("%d",&reqres);
	if(reqproc>=m && reqres>=n)
	{
		printf("Invalid request\n");
	}
	printf("Enter the number of resource instances\n");
	int request;
	scanf("%d",&request);
	if(request<=cpyneed[reqproc][reqres] && request<=cpyavailable[reqres])
	{
		cpyavailable[reqres]=cpyavailable[reqres]-request;
		cpyallocation[reqproc][reqres]+=request;
		cpyneed[reqproc][reqres]-=request;
		bool reqsafe=checksafety(cpycompleted,cpyavailable,cpyneed,cpyallocation,m,n);
		if(reqsafe)
		{
			printf("Request was granted as the resource allocation is safe\n");
		}
		else
		{
			printf("Request denied as it causes unsafe state\n");
		}
		
	}
	else
	{
		printf("Request denied due to unavailable resources or exceeding max need\n");
	}
	
    }
}
