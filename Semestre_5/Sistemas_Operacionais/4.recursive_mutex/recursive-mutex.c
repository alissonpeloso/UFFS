/* Dica para compilação:
                         gcc -o rec recursive-mutex.c -lpthread */

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void *mythread(void *data);

pthread_mutex_t count_mutex; // = PTHREAD_MUTEX_INITIALIZER;

pthread_mutexattr_t mta;

#define N 2 // number of threads

void print_global(int id);

int x = 0;

int main(void) {
  pthread_t tids[N];
  int i = 0;

  // Exemplo de como inicializar um mutex recursivo
  pthread_mutexattr_init(&mta);
  pthread_mutexattr_settype(&mta, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&count_mutex, &mta);

  for (i = 0; i < N; i++) {
    int *j = malloc(sizeof(int));
    *j = i;
    pthread_create(&tids[i], NULL, mythread, (void *)j);
  }
  /* We will now wait for each thread to<\n>
   * terminate */
  for (i = 0; i < N; i++) {
    pthread_join(tids[i], NULL);
    printf("Thread id %ld returned\n", tids[i]);
  }
  return (1);
}

void *mythread(void *data) {
  int id;
  id = *((int *)data);
  free((int *)data);

  // demonstração tratamento exclusão mútua utilizando mutex
  while (x < 10) {

    pthread_mutex_lock(&count_mutex);

    x++;

    print_global(id);

    pthread_mutex_unlock(&count_mutex);

    sleep(1);
  }

  /* We can return a pointer. Whatever pointer
   * we return can later be retrieved using the
   * pthread_join function */
  pthread_exit(NULL);
}

void print_global(int id) {

  pthread_mutex_lock(&count_mutex);

  printf("(USING MUTEX)  Thread ID %d: x is now %d \n", id, x);

  pthread_mutex_unlock(&count_mutex);
}