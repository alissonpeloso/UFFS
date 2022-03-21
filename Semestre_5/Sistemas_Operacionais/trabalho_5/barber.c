//Aluno: Alisson Luan de Lima Peloso

// `./nome_do_programa {número de assentos} {número de clientes}`.

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CUTTING_TIME 5
#define MAX_CUSTOMER_WALK 8

sem_t barberReady;
sem_t accessSeats; /*if 1, the number of seats in the waiting room can be incremented or decremented*/
sem_t custReady; /*the number of customers currently in the waiting room, ready to be served*/
pthread_t *customers;
pthread_t barber;
int numberOfFreeWRSeats; /*total number of seats in the waiting room*/
int dailyServices; /*total number of services to do today*/

void *barberThread();
void *customerThread();

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Error! Try to use 'prog {seats} {customers}', when 'prog' is the name of the compiled program and all parameters are integers.\n");
        exit(0);
    }

    int nCustomers = strtol(argv[2], NULL, 10);
    numberOfFreeWRSeats = strtol(argv[1], NULL, 10);
    dailyServices = nCustomers;

    if(nCustomers <= numberOfFreeWRSeats+1){
        printf("Error! The number of customers must be bigger than the number of seats + 1\n");
        exit(0);
    }

    sem_init(&barberReady, 0, 0);
    sem_init(&accessSeats, 0, 1);
    sem_init(&custReady, 0, 0);

    // allocating customers
    customers = calloc(sizeof(pthread_t), nCustomers);
    if (customers == NULL){
        printf("calloc error");
    }

    // create Barber
    pthread_create(&barber, NULL, barberThread, NULL);

    // create Customers
    for(long customer = 0; customer < nCustomers; customer++){
        pthread_create(&customers[customer], NULL, customerThread,(void *)customer);
    }

    // join Barber
    pthread_join(barber, NULL);

    // join Customers
    for(long customer = 0; customer < nCustomers; customer++){
        pthread_join(customers[customer], NULL);
    }

    return 1;
}

void *barberThread(){
    for(;;){
        if(dailyServices == 0){
            printf("Barber: all today's customers were served\n");
            return NULL;
        }
        printf("Barber: Checking if customers are in the waiting room\n");
        sem_wait(&custReady);
        sem_wait(&accessSeats);
        printf("Barber: Calling a customer to get a haircut\n");
        numberOfFreeWRSeats++;
        dailyServices--;
        sem_post(&barberReady);
        sem_post(&accessSeats);
        printf("Barber: Cutting hair\n");
        sleep(rand() % MAX_CUTTING_TIME);
    } 
}

void *customerThread(void * number){
    long id = (long) number;
    for(;;){
        sleep(rand() % MAX_CUSTOMER_WALK);
        sem_wait(&accessSeats);
        if (numberOfFreeWRSeats > 0){
            numberOfFreeWRSeats--;
            printf("Customer %ld: I'm sitting on a seat\n", id);
            sem_post(&custReady);
            sem_post(&accessSeats);
            sem_wait(&barberReady);
            printf("Customer %ld: Having a haircut\n", id);
            return NULL;
        }
        else{
            sem_post(&accessSeats);
            printf("Customer %ld: Leave without a haircut\n", id);
        }
    }
}
