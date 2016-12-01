#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
sem_t empty;
sem_t full;
sem_t sema;
int item=0;

void producer(void *param) {
  sem_wait(&empty);
  sem_wait(&sema);

  printf("Item count: %d\n", ++item);

  sem_post(&full);
  sem_post(&sema);

  pthread_exit(NULL);
}

void consumer(void *param) {
  sem_wait(&full);
  sem_wait(&sema);

  printf("Item count: %d\n", --item);

  sem_post(&empty);
  sem_post(&sema);

  pthread_exit(NULL);
}


int main() {
  sem_init(&empty, 0, 5);
  sem_init(&full, 0, 0);
  sem_init(&sema, 0, 1);
  int i;
  pthread_t producerid[10];
  pthread_t consumerid[10];
  for (i=0; i<10; i++) {
    pthread_create(&producerid[i], NULL, (void*)producer, NULL);
    pthread_create(&consumerid[i], NULL, (void*)consumer, NULL);
  }

  for(i=0;i<4;i++){
    pthread_join(producerid[i],NULL);
    pthread_join(consumerid[i],NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&sema);

  pthread_exit(NULL);
}
