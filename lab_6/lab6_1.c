#include <stdio.h>
#include <unistd.h>

int golbal = 10;

int main() {
  int local = 10;

  printf("Golbal: %d\n", golbal);
  printf("Local:  %d\n", local);
  printf("Pid:    %d\n", getpid());

  pid_t new_pid;
  new_pid = fork();

  switch(new_pid) {
    case -1:
        printf("fork error!\n");
        break;
    case 0: // create a child process
        printf("\n----------This is child process----------\n");
        printf("Golbal:     %d\n", golbal);
        printf("Local:      %d\n", local);
        printf("Pid:        %d\n", getpid());
        printf("Parent Pid: %d\n",getppid());
        golbal++;
        local++;
        break;
    default:
        wait();
        break;
  }

  switch(new_pid) {
    case -1:
        printf("fork error!\n");
        break;
    case 0: // create a child process
        printf("\n----------This is child process----------\n");
        printf("Golbal:     %d\n", golbal);
        printf("Local:      %d\n", local);
        printf("Pid:        %d\n", getpid());
        printf("Parent Pid: %d\n",getppid());
        break;
    default:
        printf("--------------------\n");
        printf("Golbal:     %d\n", golbal);
        printf("Local:      %d\n", local);
        printf("Pid:        %d\n", getpid());
        printf("Parent Pid: %d\n",getppid());
        wait();

        break;
  }
  return 0;

}
