#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

pthread_barrier_t barrier0;
pthread_barrier_t barrier1;
pthread_t *threads;

double *newArray;
double *oldArray;
double *tempArray;

int sliceSize;
int N;
double n;
int nThreads;
int nIterations;

void *threadFunc();
void printLine();

int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Error! Try to use 'prog {threads} {iterations} {arraySize}', when 'prog' is the name of the compiled program and all parameters are integers.\n");
        exit(0);
    }

    n = strtol(argv[3], NULL, 10);
    N = n+2;
    nThreads = strtol(argv[1], NULL, 10);
    nIterations = strtol(argv[2], NULL, 10);

    if(nThreads > n){
        printf("Error! The number of threads must be less than the array size\n");
        exit(0);
    }

    sliceSize = ceil(n/nThreads);
    printf("slice = %d\n", sliceSize);

    // allocating new and old arrays
    newArray = calloc(N, sizeof(double));
    newArray[N-1] = 1.0;

    oldArray = calloc(N, sizeof(double));
    oldArray[N-1] = 1.0;

    // allocating threads
    threads = calloc(sizeof(pthread_t), nThreads);
    if (threads == NULL){
        printf("calloc error");
    }

    pthread_barrier_init(&barrier0, NULL, nThreads);
    pthread_barrier_init(&barrier1, NULL, nThreads);


    for(long thread = 0; thread < nThreads; thread++){
        pthread_create(&threads[thread], NULL, threadFunc,(void *)thread);
    }

    for(long thread = 0; thread < nThreads; thread++){
        pthread_join(threads[thread], NULL);
    }

    printLine();

    return 1;
}

void *threadFunc(void * number){
    int ret0, ret1;
    long id = (long) number;
    int start = id * sliceSize + 1;
    int end = start + sliceSize -1;
    if(end > (N-2)){
        end = N - 2;
    }

    printf("Thread %ld is starting | start: %d end: %d\n", id, start, end);

    for(int iteration = 1; iteration <= nIterations; iteration++){
        for(int i = start; i <= end; i++){
            newArray[i] = (oldArray[i-1] + oldArray[i+1])/2;
        }
        
        ret0 = pthread_barrier_wait(&barrier0);

        if (ret0 == 0) {
            // printf("Thread %ld passed barrier 0. return value was 0\n", id);

        } else if (ret0 == PTHREAD_BARRIER_SERIAL_THREAD) {
            printf("Thread %ld passed barrier 0. return value was PTHREAD_BARRIER_SERIAL_THREAD\n", id);
            tempArray = newArray;
            newArray = oldArray;
            oldArray = tempArray;

            printf("swap done sucefull by thread %ld\n", id);
                
        } else {    
            printf("Error pthread_barrier_wait (%ld)\n", id);
        }

        ret1 = pthread_barrier_wait(&barrier1);

        if (ret1 == 0) {
            // printf("Thread %ld passed barrier 1. return value was 0\n", id);

        } else if (ret1 == PTHREAD_BARRIER_SERIAL_THREAD) {
            printf("Thread %ld passed barrier 1. return value was PTHREAD_BARRIER_SERIAL_THREAD\n", id);
                
        } else {    
            printf("Error pthread_barrier_wait (%ld)\n", id);
        }

        printf("iteration %d completed, thread %ld\n\n", iteration, id);
    }

    return NULL;
}

void printLine(){
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%f, ", oldArray[i]);
    }
    printf("\n\n");
}