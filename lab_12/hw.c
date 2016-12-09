#include <stdio.h>
#include <stdlib.h>
#include <time.h>     //for random


// record each page map to frame
int r[6];
int ascChar[32];


void Init();
void Paging();
void Result();



int main() {
  // initial
  Init();
  Paging();
  Result();
  return 0;
}

void Paging() {
  printf("Step2: Paging\n");

  int i = 0, j = 0, asc = 65;
  // set random seed
  srand(time(NULL));

  for(i = 0; i < 6; i++){
    r[i] = rand() % 16;
    if( i != 0){
      for(j = 0; j < i; j++){
        if(r[j] == r[i]){
          i--;
          break;
        }
      }
    }
  }

  for(i = 0; i < 6; i++){
    if(i < 3) {
      printf("\t Process 0 Page(%d) -> frame(%d)\n", i, r[i]);
    }
    else {
      printf("\t Process 1 Page(%d) -> frame(%d)\n", i, r[i]);
    }

    ascChar[r[i] * 2] = asc;
    asc++;
    ascChar[r[i] * 2 + 1 ] = asc;
    asc++;
  }

  printf("FreeFrameList[10]: ");
  for(i = 0; i < 16; i++){
    if( i != r[0] && i != r[1] && i != r[2] && i != r[3] && i != r[4] && i != r[5]){
      printf("%d, ", i);
    }
  }
  printf("\n");

}

void Result() {
  int i = 0, j = 0 , asc = 65;
  printf("Step3: Result\n");

  printf("*****Logical Memory*****\n");
  printf("----  Frame\tEntry\tData----\n");
  for(i = 0; i < 12; i++ , asc++){
    printf("-\t%d\t %d\t %c-----\n", i/2, i, asc);
  }

  printf("Process 0:\n");
  printf("*******Page Table*******\n");
  printf("-------Page   Frame-----\n");
  for(i = 0; i <3 ; i++){
    printf("-\t%d\t%d\t-----\n", i, r[i]);
  }
  printf("Process 1:\n");
  printf("*******Page Table*******\n");
  printf("-------Page   Frame-----\n");
  for(i = 3; i <6 ; i++){
    printf("-\t%d\t%d\t-----\n", i, r[i]);
  }

  printf("*****Physical Memory*****\n");
  printf("----  Frame\tEntry\tData----\n");

  int entry=0;
  for(i = 0;i <16; i++, entry+=2) {
    if(i == r[0] || i == r[1] || i == r[2] || i == r[3] || i == r[4] || i == r[5]) {
      printf("-\t%d\t %d\t %c-----\n", i, entry, ascChar[i * 2]);
      printf("-\t%d\t %d\t %c-----\n", i, entry+1, ascChar[i * 2 +1]);
    }
    else {
      printf("-\t%d\t %d\t ?-----\n", i, entry);
      printf("-\t%d\t %d\t ?-----\n", i, entry+1);
    }
  }
  printf("FreeFrameList[10]: ");
  for(i = 0; i < 16; i++){
    if( i != r[0] && i != r[1] && i != r[2] && i != r[3] && i != r[4] && i != r[5]){
      printf("%d, ", i);
    }
  }
  printf("\n\n");
}

void Init() {
  printf("Step1: Initialization\n");
  printf("Process 0:\n");
  printf("*******Page Table*******\n");
  printf("-------Page---Frame-----\n");
  printf("-        -1      -1-----\n");
  printf("-        -1      -1-----\n");
  printf("-        -1      -1-----\n");
  printf("Process 1:\n");
  printf("*******Page Table*******\n");
  printf("-------Page   Frame-----\n");
  printf("-        -1      -1-----\n");
  printf("-        -1      -1-----\n");
  printf("-        -1      -1-----\n");
  printf("*****Logical Memory*****\n");
  printf("----Page/Entry--Data----\n");
  printf("-      0     0     ?----\n");
  printf("-      0     1     ?----\n");
  printf("-      1     2     ?----\n");
  printf("-      1     3     ?----\n");
  printf("-      2     4     ?----\n");
  printf("-      2     5     ?----\n");
  printf("-      3     6     ?----\n");
  printf("-      3     7     ?----\n");
  printf("-      4     8     ?----\n");
  printf("-      4     9     ?----\n");
  printf("-      5    10     ?----\n");
  printf("-      5    11     ?----\n");
  printf("*****Physical Memory*****\n");
  printf("----Page/Entry--Data----\n");
  printf("-      0     0     ?----\n");
  printf("-      0     1     ?----\n");
  printf("-      1     2     ?----\n");
  printf("-      1     3     ?----\n");
  printf("-      2     4     ?----\n");
  printf("-      2     5     ?----\n");
  printf("-      3     6     ?----\n");
  printf("-      3     7     ?----\n");
  printf("-      4     8     ?----\n");
  printf("-      4     9     ?----\n");
  printf("-      5    10     ?----\n");
  printf("-      5    11     ?----\n");
  printf("-      6    12     ?----\n");
  printf("-      6    13     ?----\n");
  printf("-      7    14     ?----\n");
  printf("-      7    15     ?----\n");
  printf("-      8    16     ?----\n");
  printf("-      8    17     ?----\n");
  printf("-      9    18     ?----\n");
  printf("-      9    19     ?----\n");
  printf("-     10    20     ?----\n");
  printf("-     10    21     ?----\n");
  printf("-     11    22     ?----\n");
  printf("-     11    23     ?----\n");
  printf("-     12    24     ?----\n");
  printf("-     12    25     ?----\n");
  printf("-     13    26     ?----\n");
  printf("-     13    27     ?----\n");
  printf("-     14    28     ?----\n");
  printf("-     14    29     ?----\n");
  printf("-     15    30     ?----\n");
  printf("-     15    31     ?----\n");
  printf("FreeFrameList[16]: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15\n\n");
}
