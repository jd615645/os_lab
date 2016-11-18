#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	printf("orig process, PID: %d\n", getpid());

	int newPid = fork();

	if (newPid == 0) { // child process
		printf("child process, PID: %d\n", getpid());

		while (1) {
			printf("still run\n");
			sleep(1);
		}
	}
	else if (newPid > 0) {
		printf("wait for 1 sec to make sure the child process is created\n");
		sleep(1); // wait for 1 sec to make sure the child process is created
		kill(newPid, SIGTERM);
		printf("child process killed\n");
	}
	else { // error forking
		printf("Could not fork()\n");
		return -1;
	}
}
