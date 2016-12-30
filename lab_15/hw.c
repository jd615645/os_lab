#include <stdio.h>
#include <fcntl.h> // for open(), close(), read()
#include <string.h> // for memset()
#include <sys/select.h> // for FD_*, select()
#include <limits.h> // for PIPE_BUF

int main() {
	char buffer[PIPE_BUF];
  fd_set tmpset;
  struct timeval tv;
  int fd1 = open("fifo1", O_RDWR);
  int fd2 = open("fifo2", O_RDWR);
  int maxfdp1, ready;
  if(fd1 > fd2) {
    maxfdp1 = fd1;
  }
  else {
    maxfdp1 = fd2;
  }
  maxfdp1++;

  while(1) {
    FD_ZERO(&tmpset);
    FD_SET(fd1, &tmpset);
    FD_SET(fd2, &tmpset);
    tv.tv_sec = 2;
    tv.tv_usec = 0;


    memset(&buffer, 0, PIPE_BUF);
    ready = select(maxfdp1, &tmpset, NULL, NULL, &tv);
    if (ready < 0){
      printf("Faill!!\n");
    }
    else if(ready == 0) {
      printf("Timeout.Try another select().\n");
    }
    else {
      if(FD_ISSET(fd1, &tmpset)) {
        printf("DEVICE 1 can read.\n");
        read(fd1,&buffer, PIPE_BUF);
        printf("%s\n", buffer);
      }
      if(FD_ISSET(fd2, &tmpset)) {
        printf("DEVICE 2 can read.\n");
        read(fd2, &buffer,PIPE_BUF);
        printf("%s\n", buffer);
      }
    }

  }

  return 0;
}
