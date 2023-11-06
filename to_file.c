#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Not enough arguments\n");
		return 1;
	}

	int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0) {
		perror("Error opening output file");
		return 1;
	}

	if (dup2(fd, STDOUT_FILENO) < 0) {
		perror("Error redirecting to STDOUT");
		return 1;
	}
	close(fd);
	execlp(argv[1], argv[1], NULL);

	perror("exec failed");
	return 1;

}

