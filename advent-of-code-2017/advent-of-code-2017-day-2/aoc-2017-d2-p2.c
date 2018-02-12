#include <stdio.h>
#include <string.h>
#include <limits.h>

#define NAME "\nAdvent Of Code 2017 Day 2 Part 2\n\n"
#define INPUT_FILE "p1-input.txt"
#define MAX_ROW 100
#define MAX_COL 100
#define DELIMITERS " \t"

void init_matrix(int matrix[][]);

main(void) {
	printf(NAME);

	// char filename[] = "p1-input.txt";
	char filename[] = "p2-test-input-1.txt";

	printf("Input file: %s\n", filename);

	int matrix[MAX_ROW][MAX_COL];
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			matrix[i][j] = INT_MIN;
		}
	}

	FILE *file;
	file = fopen(filename, "r");
	if (file) {
		int i = 0;
		while (fgets(buf, sizeof buf, file) != NULL) {
			char* item;
			item = strtok(buf, DELIMITERS);
			int j = 0;
			while (item != NULL) {
				matrix[i][j] = strtol(item, NULL, 10);
				item = strtok(NULL, DELIMITERS);
				++j;
			}
			++i;
		}
	}
	else {
		printf("Could not open file %s", filename);
		return 1;
	}
	fclose(file);

	return 0;
}