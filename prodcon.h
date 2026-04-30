#ifndef PRODCON_H
#define PRODCON_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 6
#define NUM_CONSUMERS 2
#define NUM_ITEMS 20

extern int buffer[BUFFER_SIZE];
extern int buf_in;
extern int buf_out;
extern int buf_count;

extern sem_t sem_empty;
extern sem_t sem_full;

extern pthread_mutex_t buf_mutex;
extern pthread_mutex_t done_mutex;
extern pthread_mutex_t iter_mutex;
extern pthread_cond_t cond_done;

extern int done_count;
extern int cons_iter;

void* producer(void *arg);
void* consumer(void *arg);

#endif