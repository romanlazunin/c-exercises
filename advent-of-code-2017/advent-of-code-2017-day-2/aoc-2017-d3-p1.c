#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NAME "Advent of Code 2017 Day 3 Part 1\n"

main(int argc, char **argv) {
	printf(NAME);

	int steps = INT_MAX;
	int value = INT_MAX;

	if (argc > 1) {
		value = atoi(argv[1]);
	}

	printf("\nValue: %d", value);

	printf("\nSteps required: %d\n", steps);

	return 0;
}