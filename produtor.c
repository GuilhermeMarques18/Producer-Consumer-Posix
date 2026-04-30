#include "prodcon.h"

int buffer[BUFFER_SIZE];
int buf_in = 0;
int buf_out = 0;
int buf_count = 0;

sem_t sem_empty;
sem_t sem_full;
pthread_mutex_t buf_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t done_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t iter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_done = PTHREAD_COND_INITIALIZER;

int done_count = 0;
int cons_iter = 0;


void *producer(void *arg) {
    int id = *(int *)arg;
 
    srand((unsigned int)(pthread_self() + id));
 
    for (int iter = 1; iter <= NUM_ITEMS; iter++) {
        int value = (rand() % 1000) + 1;   
 
        sem_wait(&sem_empty);
 
        pthread_mutex_lock(&buf_mutex);
        buffer[buf_in] = value;
        buf_in = (buf_in + 1) % BUFFER_SIZE;
        buf_count++;
        pthread_mutex_unlock(&buf_mutex);
 
        sem_post(&sem_full);
 
        printf("(P) TID: %d | VALOR: R$ %4d | ITERACAO: %2d\n",
               id, value, iter);
        fflush(stdout);
 
        sleep((rand() % 5) + 1);
    }
 
    printf("(P) TID: %d finalizou\n", id);
    fflush(stdout);
 
    pthread_mutex_lock(&done_mutex);
    done_count++;
    pthread_cond_broadcast(&cond_done);
    pthread_mutex_unlock(&done_mutex);
 
    return NULL;
}