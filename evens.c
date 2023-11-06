#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Invalid Argument: Must Be 1 Argument\n");
		return 1;
	}
	char *endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (*endptr != '\0') {
		fprintf(stderr, "Invalid Argument: Must be Int\n");
		return 1;
	}
	if (n < 1) {
		fprintf(stderr, "Invalid Argument: Must be Positive Int\n");
	}

	for (int i = 2; i <= n; i += 2) {
		printf("%d\n", i);
	}
	return 0;
}
