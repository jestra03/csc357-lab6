#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	pid_t p1;
	p1 = fork();
	if (p1 < 0) {
		perror("Fork failed");
		return 1;
	}
	else if (p1 == 0) {
		execlp("./odds", "./odds", argv[1], NULL);
		perror("exec failed");
		exit(1);
	}
	else {
		pid_t p2 = fork();
		if (p2 < 0) {
			perror("Fork failed");
			return 1;
		}
		else if (p2 == 0) {
			execlp("./evens", "./evens", argv{1], NULL);
			perror("exec failed");
			exit(1);
		}
		wait(NULL);
	}
	return 0;
}	
