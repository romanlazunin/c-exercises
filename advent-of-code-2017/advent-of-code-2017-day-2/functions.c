#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_ROW 100
#define MAX_COL 100

int get_sum(int matrix[MAX_ROW][MAX_COL]) {
	int sum = 0;
	for (int i = 0; i < MAX_ROW && matrix[i][0] != INT_MIN; i++) {

		int max = INT_MIN;
		int min = INT_MAX;

		int next_row = 0;
		for (int j = 0; j < MAX_COL && matrix[i][j] != INT_MIN && next_row == 0; j++) {

			max = matrix[i][j];

			printf(" Max: %d", max);

			for (int k = 0; k < MAX_COL && matrix[i][k] != INT_MIN && next_row == 0; k++) {
				if (k != j && (matrix[i][j] % matrix[i][k] == 0)) {
					min = matrix[i][k];
					printf(" Min: %d", min);
					next_row = 1;
				}
			}
		}

		if (max != INT_MIN && min != INT_MAX) {
			sum += max / min;
		}
	}
	return sum;
}