#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH 0x50

int main (int argc, char *argv[]) {
  int fd, count;
  char str[80] = {0};
  void *file_memory;

  fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);

  lseek(fd, 1, SEEK_SET);
  write(fd, "", FILE_LENGTH);

  file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);

  close(fd);

  count = strlen(file_memory);
  // printf("count1: %d\n",count);

  while(1 && count <= 80){
    printf("Enter any character: ");
    gets(str);
    count = strlen(file_memory);
    sprintf((char*)(file_memory+count), "%s", str);

    // count = strlen(file_memory);
    // printf("count2: %d\n", count);
  }

  munmap((char*)file_memory, FILE_LENGTH);
  return 0;
}
