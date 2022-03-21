#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t condition_var0 = PTHREAD_COND_INITIALIZER;
pthread_cond_t condition_var1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t condition_var2 = PTHREAD_COND_INITIALIZER;

void *threadFunction0();
void *threadFunction1();
void *threadFunction2();
void *initializerFuncion();

int global = 0;
#define COUNT_DONE 12
#define N_THREADS 3

int main() {
  pthread_t thread0, thread1, thread2;

  pthread_create(&thread0, NULL, &threadFunction0, NULL);
  pthread_create(&thread1, NULL, &threadFunction1, NULL);
  pthread_create(&thread2, NULL, &threadFunction2, NULL);

  pthread_join(thread0, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("\nFinal global value: %d\n", global);

  return 1;
}

void *threadFunction0() {
  for (;;) {
    pthread_mutex_lock(&count_mutex);

    printf("Thread 0 | pegou o mutex \n");

    pthread_cond_wait(&condition_var0, &count_mutex);

    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var1);
      pthread_exit(NULL);
    }

    global++;
    printf("Thread 0 | Global = %d\n", global);
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&condition_var1);
  }
}

void *threadFunction1() {
  for (;;) {
    pthread_mutex_lock(&count_mutex);

    printf("Thread 1 | pegou o mutex \n");

    pthread_cond_wait(&condition_var1, &count_mutex);

    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var2);
      pthread_exit(NULL);
    }

    global++;
    printf("Thread 1 | Global = %d\n", global);
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&condition_var2);
  }
}

void *threadFunction2() {
  for (;;) {
    pthread_mutex_lock(&count_mutex);

    if (global == 0) {
      pthread_cond_signal(&condition_var0);
    }

    printf("Thread 2 | pegou o mutex \n");

    pthread_cond_wait(&condition_var2, &count_mutex);

    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var0);
      pthread_exit(NULL);
    }

    global++;
    printf("Thread 2 | Global = %d\n", global);
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&condition_var0);
  }
}