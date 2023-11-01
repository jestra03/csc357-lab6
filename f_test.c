#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>

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
	
	int p;
	p = fork();
	for (int i = 0; i <= n; i++) {
		if (p < 0) {
			perror("fork fail");
			exit(1);
		}
		else if (p == 0) {
			printf("%d", i);
		}
		else {
			printf("%d", i);
		}
		
	
	}
	
	return 0;
}

