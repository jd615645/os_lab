#include <stdio.h>
#include <unistd.h>
#include "rand.h"
#include <sys/time.h>

int main() {
	int i;
	int maxNum = 0;	

        struct timeval start;
        struct timeval end;
        unsigned long diff;

        gettimeofday(&start, NULL);
	
	for (i=0; i<10000000; i++) {
		maxNum = (maxNum < arr[i]?arr[i]:maxNum);
	}
	printf("Max number is %d\n", maxNum);

        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

        printf("time spent is %ld\n us", diff);

        return 0;
}

