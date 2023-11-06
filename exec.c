#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	pid_t p1, p2;
	p1 = fork();
	if (p1 < 0) {
		perror("Fork failed");
		return 1;
	}
	else if (p1 == 0) {
		execlp("./odds", "./odds", NULL);
		perror("exec failed");
		exit(1);
	}

	p2 = fork();
	if (p2 < 0) {
		perror("Fork failed");
		return 1;
	}
	else if (p2 == 0) {
		execlp("./evens", "./evens", NULL);
		perror("exec failed");
		exit(1);
	}
	return 0;
}	
