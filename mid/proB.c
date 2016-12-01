#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "rand.h"
#include <sys/time.h>

int maxNum[5];
void *findMaxNum(void *arg) {
	int i;
	int thread = (int)arg + 1;
	int thisMaxNum = 0;
	for (i=(thread-1)*2000000; i<thread*2000000; i++) {
		thisMaxNum = (thisMaxNum < arr[i]?arr[i]:thisMaxNum);
	}
	maxNum[thread] = thisMaxNum;
	printf("[Thread %d] Max number is %d\n", thread, thisMaxNum);
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[5];
	int rc, t;

        struct timeval start;
        struct timeval end;
        unsigned long diff;

        gettimeofday(&start, NULL);
	
	for (t=0; t<5; t++) {
		rc = pthread_create(&threads[t], NULL, findMaxNum, (void *)t);
		if (rc) {
			printf("ERROR return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	// maxNum = (maxNum < arr[i]?arr[i]:maxNum);
	for (t=0; t<5; t++) {
		rc = pthread_join(threads[t], NULL);
		if (rc) {
			printf("ERROR return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	int i;

	int theMaxNum = maxNum[1];
	for (i=2; i<=5; i++) {
		if(theMaxNum<maxNum[i]) {
			theMaxNum = maxNum[i];
		}
	}
	
	printf("Max number is %d\n", theMaxNum);

        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

        printf("time spent is %ld\n us", diff);

        return 0;
}

