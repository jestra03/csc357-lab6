#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		perror("Must be one argument");
		return 1;
	}
	char *endptr;
	int n = strtol(argv[1], &endptr , 10);
	if (*endptr != '\0') {
		perror("invalid argument");
		return 1;
	}
	
	pid_t  p;
	p = fork();
	if (p < 0) {
		perror("fork fail");
		exit(1);
	}
	else if (p == 0) {
		for (int i = 1; i <= n; i += 2) {
			printf("%d\n", i);
		}
		exit(0);
	}
	else {
		wait(NULL);
		for (int i = 2; i <= n; i += 2) {
			printf("\t%d\n", i);
		}
	}
	
	return 0;
}

