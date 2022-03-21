//Aluno: Alisson Luan de Lima Peloso

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define THINKING_TIME 3
#define EATING_TIME 2

int state[N];
sem_t mutex;
sem_t s[N];
pthread_t threads[N];

void philosopher(int);
void test(int);
void take_forks(int);
void put_forks(int);

void think(int);
void eat(int);

int main(){
    sem_init(&mutex, 0, 1);

    for(int i = 0; i < N; i++){
        sem_init(&s[i], 0, 0);
        pthread_create(&threads[i], NULL, (void *) philosopher, (void *) (intptr_t) i);
    }

    for(int i = 0; i < N; i++){
        pthread_join(threads[i], NULL);
    }

    printf("\n*** All philosophers ate their meal! ***\n");
}

void philosopher(int i){
    think(i);
    take_forks(i);
    eat(i);
    put_forks(i);
}

void take_forks(int i){
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("philosopher nº %d is HUGRY\n", i);
    test(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
}

void put_forks(int i){
    sem_wait(&mutex);
    printf("philosopher nº %d is putting the forks on the table\n", i);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void test(int i){
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[i] = EATING;
        sem_post(&s[i]);
    }
    else if(state[i] == HUNGRY){
        printf("\tThere are not enough forks available for the philosopher nº %d\n", i);
    }
}

void think(int i){
    srand(time(NULL));
    printf("philosopher nº %d is thinking now!\n", i);
    sleep(rand() % THINKING_TIME);
}

void eat(int i){
    srand(time(NULL));
    printf("philosopher nº %d is eating now!\n", i);
    sleep(rand() % EATING_TIME);
}