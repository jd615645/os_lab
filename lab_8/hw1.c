#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;
void *PrintHello(void *arg)  {
	int i;
	printf("\n----------\n");
	printf("Thread: %d Thread ID: %lu\n",(int) arg,pthread_self());
	for (i = 0; i < 250000; i++) {
		count +=1;
		if (count == 100000) {
			// printf("100000 O w O\n");
		}
	}
	pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
	pthread_t threads[4];
	int rc;
	int t;
	for(t = 0; t < 4; t++) {
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		// rc = pthread_join(threads[t], NULL);
		// if (rc) {
		// 	printf("ERROR; return code from pthread_join() is %d\n", rc);
		// 	exit(-1);
		// }
	}
	for(t = 0; t < 4; t++) {
		rc = pthread_join(threads[t], NULL);
		if (rc) {
			printf("ERROR; return code from pthread_join() is %d\n", rc);
			exit(-1);
		}
	}
	printf("----------\n");
	printf("This is main program.\n");
	printf("value= %d\n", count);
	return 0;
}
