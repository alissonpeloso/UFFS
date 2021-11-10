/* Dica para compilação: 
                         gcc -o test1 testThread.c -lpthread */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 


void *mythread(void *data);

#define N 5 // number of threads

int main(void) {
   pthread_t tids[N];
   int i=0;


   
   for(i=0; i<N; i++) {
      int *j = malloc(sizeof(int));
      *j = i;
      pthread_create(&tids[i], NULL, mythread, (void *)j);
   }
   /* We will now wait for each thread to<\n>
    * terminate */
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
   
   printf("\n I am thread %d \n", id);
   sleep(1);
   /* We can return a pointer. Whatever pointer
    * we return can later be retrieved using the
    * pthread_join function */
   pthread_exit(NULL);
}