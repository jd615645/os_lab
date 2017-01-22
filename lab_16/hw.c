#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

// struct dirent {
//   ino_t d_ino;     // i-node num
//   char d_name[];   // file name
// }

int main() {
  DIR *dp;
  char *dir = "/home/sakamoto/os_lab/lab_16/file";
  struct dirent *entry;

  dp = opendir(dir);
  while ( (entry=readdir(dp)) != NULL ) {
    if(entry -> d_name[0] != '.') {
      printf("%s\n", entry -> d_name);
    }
  }

  closedir(dp);
  return 0;
}
