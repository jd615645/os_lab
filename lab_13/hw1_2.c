#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct flock* file_lock(short type, short whence) {
  static struct flock ret;
  ret.l_type = type;
  ret.l_start = 0;
  ret.l_whence = whence;
  ret.l_len = 0;
  return &ret;
}

int main() {
  int input, flag, unl;
  int fd = open("lock.txt", O_RDWR|O_APPEND);
  printf("Choosin lock;\n");
  printf("1) exclusive lock(write lock).\n");
  printf("2) share lock(read lock).\n");
  scanf("%d", &input);
  getchar();

  if(input == 1) {
    flag = fcntl(fd, F_SETLKW, file_lock(F_WRLCK, SEEK_SET));
    if(flag == -1) {
      printf("Locking file with 'WRLCk' fail, another process lock it.\n");
    }
    else {
      printf("Locking file with 'WRLCk' success, enter integer to unlock.\n");
    }
  }
  else if(input == 2) {
    flag=fcntl(fd, F_SETLKW, file_lock(F_RDLCK, SEEK_SET));
    if(flag == -1) {
      printf("Locking file with 'RDLCk' fail, another process lock it.\n");
    }
    else {
      printf("Locking file with 'RDLCk' success, enter integer to unlock.\n");
      scanf("%d", &unl);
      fcntl(fd, F_SETLKW, file_lock(F_UNLCK, SEEK_SET));
      printf("unlock success\n");
    }

  }
return 0;
}
