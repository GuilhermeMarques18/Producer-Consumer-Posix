#include "prodcon.h"

int main(void) {
    pthread_t prod_tid[NUM_PRODUCERS];
    pthread_t cons_tid[NUM_CONSUMERS];
    int       prod_id[NUM_PRODUCERS];
    int       cons_id[NUM_CONSUMERS];
 
    sem_init(&sem_empty, 0, BUFFER_SIZE);  
    sem_init(&sem_full,  0, 0);            
 
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        prod_id[i] = 1000 + i;
        pthread_create(&prod_tid[i], NULL, producer, &prod_id[i]);
    }
 
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cons_id[i] = 2000 + i;
        pthread_create(&cons_tid[i], NULL, consumer, &cons_id[i]);
    }
 
    for (int i = 0; i < NUM_PRODUCERS; i++)
        pthread_join(prod_tid[i], NULL);
    for (int i = 0; i < NUM_CONSUMERS; i++)
        pthread_join(cons_tid[i], NULL);
 
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    pthread_mutex_destroy(&buf_mutex);
    pthread_mutex_destroy(&done_mutex);
    pthread_mutex_destroy(&iter_mutex);
    pthread_cond_destroy(&cond_done);
 
    printf("\n=== Sistema encerrado ===\n");
    return 0;
}
 