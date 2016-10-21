#include <stdio.h>
#include <unistd.h>

int main(){

  // process B
  if(fork() == 0) {
    // process C
    if(fork() == 0) {
      printf("--------------------\n");
      printf("I'm child process C\n");
      printf("PID       : %d\n", getpid());
      printf("Parent PID: %d\n", getppid());
      return 0;
    }
    wait();

    printf("--------------------\n");
    printf("I'm child process B\n");
    printf("PID       : %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
    return 0;
  }
  wait();

  // process D
  if(fork() == 0) {
    printf("--------------------\n");
    printf("I'm child process D\n");
    printf("PID       : %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
    return 0;
  }
  wait();

  // process E
  if(fork() == 0) {
    printf("--------------------\n");
    printf("I'm child process E\n");
    printf("PID       : %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
    return 0;
  }
  wait();

  // process A
  printf("--------------------\n");
  printf("I'm child process A\n");
  printf("PID       : %d\n", getpid());
  printf("Parent PID: %d\n", getppid());

  return 0;
}
