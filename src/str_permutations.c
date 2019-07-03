#include "str_permutations.h"
#include "math_utils.h"

#include <string.h>
#include <stdio.h>

#include "str_utils.h"

void print_permutation(unsigned int num, char* str) {
  printf("%d --> %s\n", num, str);
}

void max_permutations(char* str) {
	int len = strlen(str);
	char* buffer = malloc(len);
	int num_perms = factorial(len);
	strcpy(buffer, str);

	int num_outer_swap_offsets = len - 3;

	int* outer_swap_offsets = malloc(num_outer_swap_offsets);

	for (int i = 0; i < num_outer_swap_offsets; i++) {
		outer_swap_offsets[i] = i + 1;
	}

	for (int i = 0; i < num_perms; i++) {
		print_permutation(i + 1, buffer);

		for (int j = 0; j < num_outer_swap_offsets; j++) {
			int offset_num_perms = num_perms;
			int offset_len = len;
			if ((i + 1) % (offset_num_perms /= offset_len) == 0) {
				swap(&buffer[len - offset_len], &buffer[outer_swap_offsets[len - offset_len]++]);
				offset_len--;
				goto end_loop;
			}
		}

		if ((i + 1) % 2 == 0) {
			swap(&buffer[len - 3], &buffer[len - 1]);
			continue;
		}
		swap(&buffer[len - 2], &buffer[len - 1]);
	end_loop:
		continue;
	}

	free(buffer);
}