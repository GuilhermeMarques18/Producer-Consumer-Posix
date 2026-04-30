#include "prodcon.h"

void *consumer(void *arg) {
    int id = *(int *)arg;
 
    while (1) {
        pthread_mutex_lock(&done_mutex);
        while (1) {
            pthread_mutex_lock(&buf_mutex);
            int current = buf_count;
            pthread_mutex_unlock(&buf_mutex);
 
            if (current >= BUFFER_SIZE) {
                pthread_mutex_unlock(&done_mutex);
                break;
            }
 
            if (done_count >= NUM_PRODUCERS) {
                pthread_mutex_unlock(&done_mutex);
                goto finished;
            }

            pthread_cond_wait(&cond_done, &done_mutex);
        }
 
        double soma = 0.0;
        for (int k = 0; k < BUFFER_SIZE; k++) {
            sem_wait(&sem_full);
 
            pthread_mutex_lock(&buf_mutex);
            soma += buffer[buf_out];
            buf_out = (buf_out + 1) % BUFFER_SIZE;
            buf_count--;
            pthread_mutex_unlock(&buf_mutex);
 
            sem_post(&sem_empty);
        }
 
        pthread_mutex_lock(&iter_mutex);
        cons_iter++;
        int iter_local = cons_iter;
        pthread_mutex_unlock(&iter_mutex);
 
        printf("(C) TID: %d | MEDIA: R$ %6.2f | ITERACAO: %2d\n",
               id, soma / BUFFER_SIZE, iter_local);
        fflush(stdout);
    }
 
finished:
    printf("(C) TID: %d finalizou\n", id);
    fflush(stdout);
    return NULL;
}