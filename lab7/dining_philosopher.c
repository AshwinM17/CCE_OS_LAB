#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//declare the states philosopher can take and semaphore
enum states{THINKING,HUNGRY,EATING};
enum states philo_state[5];
int chopsticks[5];
int philosophers_ids[5];

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}

//can philosopher eat?
void test(int i){
    if(philo_state[(i+4)%5]!=EATING && philo_state[i]==HUNGRY && philo_state[(i+1)%5]!=EATING){
        philo_state[i]=EATING;
        signal(&chopsticks[i]);
    }
}

//philosopher can pick chopstick
void pickup(int i){
    philo_state[i]=HUNGRY;
    //test if their chopsticks are available
    test(i);
    if(philo_state[i]!=EATING){
        wait(&chopsticks[i]);
    } 
}

//philosopher can put down chopstick
void putdown(int i){
    philo_state[i]=THINKING;
    //test if their neighbors want a chopstick
    test((i+4)%5);
    test((i+1)%5);
}

// Function representing the behavior of a philosopher
void *philosopher(void *arg) {
    int id = *((int *)arg);
    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 3 + 1); 

        // Pick up chopsticks
        pickup(id);
        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3 + 1); 

        // Put down chopsticks
        putdown(id);
    }
    return NULL;
}

int main(){
    int i;
    pthread_t philosophers[5];
    for (i = 0; i < 5; i++) {
        chopsticks[i]=0;
    }
    for(i=0;i<5;i++){
        philo_state[i]=THINKING;
    }

    // Create philosopher threads
    for (i = 0; i < 5; i++) {
        philosophers_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosophers_ids[i]);
    }

    // Join philosopher threads 
    for (i = 0; i < 5; i++) {
        pthread_join(philosophers[i], NULL);
    }
}