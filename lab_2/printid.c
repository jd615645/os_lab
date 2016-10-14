#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //if(seteuid(0) != 0) { printf("error seteuid!\n"); }

  printf (
    "Real       UID = %d\n"
    "Effective  UID = %d\n",
    getuid(),
    geteuid()
  );

  return 0;
}
