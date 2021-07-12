//Aluno: Alisson Luan de Lima Peloso

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_WAITING_TIME 2
#define MAX_WORKING_TIME 4

void *thread1(void *data);
void *thread2(void *data);


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER, mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_t Thread1, Thread2;

int main(void) {
    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);

    srand(time(NULL));

    //now join them
    pthread_join(Thread1, NULL);
    printf("Thread id %ld (1) returned\n", Thread1);
    pthread_join(Thread2, NULL);
    printf("Thread id %ld (2) returned\n", Thread2);

    return 1;
}

void *thread1(void *data){
    unsigned long i,j;
    int gotBoth = 0;
    while(!gotBoth){
        if(pthread_mutex_trylock(&mutex1)==0){
            printf("Thread ID%ld (1) got mutex1.\n", pthread_self());
            if(pthread_mutex_trylock(&mutex2)==0){
                printf("Thread ID%ld (1) got mutex2.\n", pthread_self());
                gotBoth = 1;
                printf("Thread ID%ld (1) got both mutexes.\n", pthread_self());
                int work = rand() % MAX_WORKING_TIME;
                printf("\n\tWORKING for %d second(s)\n\n", work);
                sleep(work);
                pthread_mutex_unlock(&mutex1);
                printf("Thread ID%ld (1) liberated mutex1.\n", pthread_self());
                pthread_mutex_unlock(&mutex2);
                printf("Thread ID%ld (1) liberated mutex2.\n", pthread_self());
            }
            else  {
                printf("Thread ID%ld (1) did not get mutex2.\n", pthread_self()); 
                pthread_mutex_unlock(&mutex1);
                printf("Thread ID%ld (1) liberated mutex1.\n", pthread_self());
                int wait = rand() % MAX_WAITING_TIME;
                printf("\tWAITING for %d second(s)\n", wait);
                sleep(wait);
            }
        }
        else { 
            printf("Thread ID%ld (1) did not get mutex1.\n", pthread_self());
            int wait = rand() % MAX_WAITING_TIME;
            printf("\tWAITING for %d second(s)\n", wait);
            sleep(wait);
        }
    }
    pthread_exit(NULL);
}

void *thread2(void *data){
    unsigned long i,j;
    int gotBoth = 0;
    while(!gotBoth){
        if(pthread_mutex_trylock(&mutex2)==0){
            printf("Thread ID%ld (2) got mutex2.\n", pthread_self());
            if(pthread_mutex_trylock(&mutex1)==0){
                printf("Thread ID%ld (2) got mutex1.\n", pthread_self());
                gotBoth = 1;
                printf("Thread ID%ld (2) got both mutexes.\n", pthread_self());
                int work = rand() % MAX_WORKING_TIME;
                printf("\n\tWORKING for %d second(s)\n\n", work);
                sleep(work);
                pthread_mutex_unlock(&mutex2);
                printf("Thread ID%ld (2) liberated mutex2.\n", pthread_self());
                pthread_mutex_unlock(&mutex1);
                printf("Thread ID%ld (2) liberated mutex1.\n", pthread_self());
            }
            else { 
                printf("Thread ID%ld (2) did not get mutex1.\n", pthread_self()); 
                pthread_mutex_unlock(&mutex2);
                printf("Thread ID%ld (2) liberated mutex2.\n", pthread_self());
                int wait = rand() % MAX_WAITING_TIME;
                printf("\tWAITING for %d second(s)\n", wait);
                sleep(wait);
            }
        }
        else { 
            printf("Thread ID%ld (2) did not get mutex2.\n", pthread_self());
            int wait = rand() % MAX_WAITING_TIME;
            printf("\tWAITING for %d second(s)\n", wait);
            sleep(wait);
        }
    }
    pthread_exit(NULL);
}