#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#define NUM_READERS 5
#define NUM_WRITERS 2

//initialize readcount and shared data
int readcount =0; 
int shared_data=0;

//binary semaphores
int mutex=1,wrt=1;

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}
bool writersexited[NUM_WRITERS]={false,false};
int exited=0;
int exitreader=1;
void *reader(void *arg) { 
    do{
        wait(&mutex);
        readcount++;
        if(readcount==1){
            wait(&wrt);
        }    
        signal(&mutex);
        //perform reading
        printf("Value read by readers %d of shared data:%d\n",readcount,shared_data);
        wait(&mutex);
        readcount--;
        if(readcount==0){
            signal(&wrt);
        }
        signal(&mutex);
        usleep(rand() % 1000000);
	
	bool exit=true;
	int i; 
	for(i=0;i<NUM_WRITERS;i++)
	{
		if(!writersexited[i])
		{
			exit=false;
		}
	}
        if(exit)
	{
		printf("Reader Thread %d Exited\n",exitreader++);
		break;
	}

    }while(1);
    pthread_exit(NULL);
}

void *writer(void *arg) {
    do{
        wait(&wrt);
        //writing is performed
        printf("Writer Modified:%d\n",shared_data);
        shared_data++;
        signal(&wrt);
        usleep(rand() % 1000000);
	if(shared_data>=5 && readcount==0){
		printf("Exiting Writer %d after 5th shared data written\n",exited+1);
		writersexited[exited++]=true;
		break;
	}
    }while (1);
    pthread_exit(NULL);
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}
