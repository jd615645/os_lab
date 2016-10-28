#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "msg_que.h"

int main() {
  int msgid;
  struct oslab_msg_st msg_buffer;
  key_t key = 0x1234;
  msgid = msgget(key, IPC_CREAT | 0666);
  printf("message queue ID: %d\n", msgid);

  while(1) {
    // retrieve messgae from the message queue
    msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 5, 0);

    printf("received: %s\n", msg_buffer.msg_text);
    if(!strncmp(msg_buffer.msg_text, "exit", 4)) {
      return 0;
    }
  }

  return 0;
}
