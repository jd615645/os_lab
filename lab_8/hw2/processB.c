#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include "msg_que.h"

int msqid;
struct oslab_msg_st msg_buffer;
struct msqid_ds msq_id;

void *mainFunction(void *arg) {
  int msqid;
  char buf[256];
  // set the key value
  key_t key = 0x1234;
  // create a message queue
  msqid = msgget(key, IPC_CREAT | 0666);

  //send function
  if((int) arg == 1) {
    while(1) {
      printf("Enter some text: ");
      fgets(buf, sizeof(buf), stdin);
      // set the message
      strcpy(msg_buffer.msg_text, buf);
      msg_buffer.oslab_msg_type = 10;
      // send the message to message queue
      msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);

      if(!strncmp(buf, "exit", 4)) {
        memset(buf, 0, sizeof(buf));

        break;
      }
      memset(buf, 0, sizeof(buf));
    }
    pthread_exit(NULL);
  }
  //receive function
  else if((int) arg == 2) {
    while(1) {
      // retrieve messgae from the message queue
      int i = msgrcv(msqid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 5, 0);
      if(i > 0) {
        printf("\nReceived: %s\n", msg_buffer.msg_text);
        if(!strncmp(msg_buffer.msg_text, "exit", 4)) {
          pthread_exit(NULL);
        }
      }
    }
  }
  else {
    printf("Error!!!\n");
  }
}


int main (int argc, char *argv[]) {
  pthread_t threadSend, threadReceive;
  int rc, rc2;

  printf("B_Process\n\n\n");


  rc = pthread_create(&threadSend, NULL, mainFunction, (void *)1);

  rc2 = pthread_create(&threadReceive, NULL, mainFunction, (void *)2);

  rc = pthread_join(threadSend, NULL);
  rc2 = pthread_join(threadReceive, NULL);

  // Remove message queue
  msgctl(msqid, IPC_RMID, &msq_id);
  printf("\n\nB_Exit\n\n");

  return 0;
}
