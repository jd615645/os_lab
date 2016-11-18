#include <signal.h>
typedef void (*sighandler_t)(int);

#include <unistd.h>
#include <stdio.h>

void handler1(int sig_num) {
	printf("How are you?\n");
}

void handler2(int sig_num) {
	printf("I am fine!\n");
}

sighandler_t defaultHandler;
void switchToDefaultHandler(int sig_num) {
	signal(SIGINT, defaultHandler);
}

void switchToHandler2(int sig_num) {
	signal(SIGINT, handler2);

	alarm(3);
	signal(SIGALRM, switchToDefaultHandler);
}

int main() {
	defaultHandler = signal(SIGINT, handler1);

	alarm(3);
	signal(SIGALRM, switchToHandler2);

	while (1) {
		pause();
	}
}
