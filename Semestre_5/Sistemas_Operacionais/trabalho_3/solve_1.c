#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t global_mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t semThread0;
sem_t semThread1;
sem_t semThread2;

void *threadFunction0();
void *threadFunction1();
void *threadFunction2();

int global = 0;

#define MAX 13
#define N_THREADS 3

int main() {
  pthread_t thread0, thread1, thread2;
  pthread_mutex_init(&global_mutex, NULL);

  sem_init(&semThread0, 0, 1);
  sem_init(&semThread1, 0, 0);
  sem_init(&semThread2, 0, 0);

  pthread_create(&thread0, NULL, &threadFunction0, NULL);
  pthread_create(&thread1, NULL, &threadFunction1, NULL);
  pthread_create(&thread2, NULL, &threadFunction2, NULL);

  pthread_join(thread0, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("\nFinal global value: %d\n", global);

  pthread_mutex_destroy(&global_mutex);

  return 1;
}

void *threadFunction0() {
  for (;;) {
    sem_wait(&semThread0);

    pthread_mutex_lock(&global_mutex);

    if (global >= MAX) {
      sem_post(&semThread1);
      pthread_mutex_unlock(&global_mutex);
      pthread_exit(NULL);
    } else {
      global++;
      printf("Thread 0 | Global = %d\n", global);
      pthread_mutex_unlock(&global_mutex);
    }

    sem_post(&semThread1);
  }
}

void *threadFunction1() {
  for (;;) {
    sem_wait(&semThread1);

    pthread_mutex_lock(&global_mutex);

    if (global >= MAX) {
      sem_post(&semThread2);
      pthread_mutex_unlock(&global_mutex);
      pthread_exit(NULL);
    } else {
      global++;
      printf("Thread 1 | Global = %d\n", global);
      pthread_mutex_unlock(&global_mutex);
    }

    sem_post(&semThread2);
  }
}

void *threadFunction2() {
  for (;;) {
    sem_wait(&semThread2);

    pthread_mutex_lock(&global_mutex);

    if (global >= MAX) {
      sem_post(&semThread0);
      pthread_mutex_unlock(&global_mutex);
      pthread_exit(NULL);
    } else {
      global++;
      printf("Thread 2 | Global = %d\n", global);
      pthread_mutex_unlock(&global_mutex);
    }

    sem_post(&semThread0);
  }
}