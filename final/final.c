#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

void eating(int arg);
sem_t chopstick[5];

int main(void) {
  int i = 0;
  for (i = 0; i < 5; i++) {
    sem_init(&chopstick[i], 0, 1);
  }

  pthread_t philosophe[5];
  for (i=0; i<5; i++) {
    pthread_create(&philosophe[i], NULL, (void*)eating, i);
  }
  for (i=0; i<5; i++) {
    pthread_join(philosophe[i], NULL);
  }
}

void eating(int arg) {
  while (1) {
    printf("%d is starving.\n", arg);

    int needChopstick[2];
    sem_getvalue(&chopstick[arg], &needChopstick[0]);
    sem_getvalue(&chopstick[(arg+1)%5], &needChopstick[1]);
    // printf("val1: %d\n", needChopstick[0]);
    // printf("val2: %d\n", needChopstick[1]);

    if(needChopstick[0] == 1 && needChopstick[1] == 1) {
      sem_wait(&chopstick[arg]);
      sem_wait(&chopstick[(arg+1)%5]);
    }


    printf("%d is think.\n", arg);
  }
  pthread_exit(NULL);
}
