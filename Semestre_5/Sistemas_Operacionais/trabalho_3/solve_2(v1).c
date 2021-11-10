#include <pthread.h>
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
int global = 0;
#define COUNT_DONE 10
#define N_THREADS 3

int main() {
  pthread_t thread0, thread1, thread2;

  pthread_mutex_init(&count_mutex, NULL);

  pthread_create(&thread0, NULL, &threadFunction0, NULL);
  pthread_create(&thread1, NULL, &threadFunction1, NULL);
  pthread_create(&thread2, NULL, &threadFunction2, NULL);

  pthread_join(thread0, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("\nFinal global value: %d\n", global);
  pthread_mutex_destroy(&count_mutex);

  return 1;
}

void *threadFunction0() { // Thread Controller
  for (;;) {
    pthread_mutex_lock(&count_mutex);

    if (global % N_THREADS == 1 && global < COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var1);
    } else if (global % N_THREADS == 2 && global < COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var2);
    } else if (global % N_THREADS == 0 && global < COUNT_DONE) {
      pthread_cond_signal(&condition_var0);
      global++;
      printf("Thread 0 | Global = %d\n", global);
      pthread_mutex_unlock(&count_mutex);
    }

    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var1);
      pthread_cond_signal(&condition_var2);
      pthread_exit(NULL);
    }
  }
}

void *threadFunction1() {
  for (;;) {
    printf("Thread 1 | Tentando pegar o mutex\n");
    pthread_mutex_lock(&count_mutex);

    // Verifica global antes de aguardar a condição (caso em que a thread
    // controller [thread 0] é finalizada antes da thread atual)
    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_exit(NULL);
    }

    pthread_cond_wait(&condition_var1, &count_mutex);
    // Verifica se o global está no máximo (caso em que o valor chega no máximo
    // e ele está aguardando a liberação)
    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_exit(NULL);
    }

    global++;
    printf("Thread 1 | Global = %d\n", global);

    pthread_mutex_unlock(&count_mutex);
  }
}

void *threadFunction2() {
  for (;;) {
    printf("Thread 1 | Tentando pegar o mutex\n");
    pthread_mutex_lock(&count_mutex);

    // Verifica global antes de aguardar a condição (caso em que a thread
    // controller [thread 0] é finalizada antes da thread atual)
    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_exit(NULL);
    }

    pthread_cond_wait(&condition_var2, &count_mutex);
    // Verifica se o global está no máximo (caso em que o valor chega no máximo
    // e ele está aguardando a liberação)
    if (global >= COUNT_DONE) {
      pthread_mutex_unlock(&count_mutex);
      pthread_exit(NULL);
    }

    global++;
    printf("Thread 2 | Global = %d\n", global);

    pthread_mutex_unlock(&count_mutex);
  }
}