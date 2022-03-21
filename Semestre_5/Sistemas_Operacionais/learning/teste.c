/* Dica para compilação: 
                         gcc -o test2 MutexESemaforo.c -lpthread */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 
#include <time.h>

void *mythread(void *data);

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

#define N 3

int x = 0;
int restrict_area = 0;

int main(void) {
   pthread_t tids[N];
   int i=0;

   for(i=0; i<N; i++) {
      int *j = malloc(sizeof(int));
      *j = i;
      pthread_create(&tids[i], NULL, mythread, (void *)j);
   }

   for(i=0; i<N; i++) {
      pthread_join(tids[i], NULL);
      printf("Thread id %ld returned\n", tids[i]);
   }
   return(1);
}

void *mythread(void *data) {
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   int id;
   id = *((int *) data);
   free((int *)data);

   // demonstração tratamento exclusão mútua utilizando mutex
   while(x < 15) {
      pthread_mutex_lock(&count_mutex);
      restrict_area = rand() % 100;
      x++;
      gettimeofday(&tv, &tz);
      tm=localtime(&tv.tv_sec);
      printf("(USING MUTEX)  Thread ID %d: x is now %d (%d:%02d:%02d:%d). restrict_area value = %i \n",id, x, tm->tm_hour, tm->tm_min, tm->tm_sec, (int)tv.tv_usec, restrict_area);
      pthread_mutex_unlock(&count_mutex);
      sleep(1);
   }
   /* We can return a pointer. Whatever pointer
    * we return can later be retrieved using the
    * pthread_join function */
   pthread_exit(NULL);
}
