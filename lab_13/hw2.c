#include <stdio.h>

int main(){
  FILE *pFile;

  char buffer[1024];

  int input = 0;
  printf("Read or Wirte?\n");
  printf("1) Read\n");
  printf("2) Wirte\n");
  scanf("%d", &input);
  getchar();

  if(input == 1) {
    pFile = fopen( "lock.txt","r" );
    if ( NULL == pFile ){
      printf( "Open fail" );
      return 1;
    }else{
      fread( buffer, 1024, 1, pFile );
      printf( "%s", buffer );
    }
    fclose(pFile);
  }
  else if(input == 2) {
    pFile = fopen( "lock.txt","w" );
    if( NULL == pFile ) {
      printf( "open failure" );
      return 1;
    }
    else {
      int a =0;
      fprintf(pFile, "OwO");
    }
    fclose(pFile);
  }


  return 0;

}
