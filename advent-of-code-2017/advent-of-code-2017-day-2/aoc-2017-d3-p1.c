#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NAME "Advent of Code 2017 Day 3 Part 1\n"

main(int argc, char **argv) {
	printf(NAME);

	int value = 1;

	if (argc > 1) {
		value = atoi(argv[1]);
	}

	if (value == 0) {
		value = 1;
	}

	printf("\nValue: %d", value);

	int row = 0;
	int width = 1;
	int length = 1;
	int max = 1;
	int min = 1;
	int max_steps = 0;
	int min_steps = row;
	int steps_required = 0;

	while (value > max) {
		max_steps = get_max_steps(row);
		min_steps = row;
		width = get_width(row);
		length = get_length(row);
		max = get_max(row);

		if (row > 0) {
			min = get_max(row - 1) + 1;
		}

		steps_required = min_steps;

		if (row == 1) {
			steps_required = value % max_steps + min_steps;
		}

		int current_steps = max_steps - 1;
		int descending = 1;
		for (int current_value = min; current_value <= max; current_value++) {
			if (value == current_value) {
				steps_required = current_steps;
			}

			if (current_steps > min_steps && descending) {
				current_steps--;
			}

			if (current_steps < max_steps && !descending) {
				current_steps++;
			}

			if (current_steps == min_steps) {
				descending = 0;
			}

			if (current_steps == max_steps) {
				descending = 1;
			}
		}

		printf("\nRow: %d; Max steps: %d; Max: %d; Width: %d; Length: %d", row, max_steps, max, width, length);
		printf("\nMin: %d:", min);
		row++;
	}

	printf("\nMax steps required: %d\n", max_steps);

	printf("\nSteps required: %d", steps_required);

	return 0;
}

int get_max_steps(int row) {
	return row * 2;
}

int get_width(int row) {
	return row * 2 + 1;
}

int get_length(int row) {
	int length = (row * 2 - 1) * 4 + 4;
	if (row == 0) {
		length = 1;
	}

	return length;
}

int get_max(int row) {
	int max = 0;
	if (row > 0) {
		max = get_max(row - 1) + get_length(row);
	}
	else {
		max = 1;
	}
	return max;
}