#include "str_permutations.h"
#include "math_utils.h"

#include <string.h>

#define MAX_PERMUTATIONS_BUFFER_SIZE 255

void print_permutation(unsigned int num, char* str) {
  printf("%d --> %s\n", num, str);
}

void swap(char* a, char* b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void max_permutations(char* str) {
  char buffer[MAX_PERMUTATIONS_BUFFER_SIZE];
  memset(buffer, 0, sizeof(MAX_PERMUTATIONS_BUFFER_SIZE));
  unsigned int len = strlen(str);

  // bail if we can't handle this string with our stack allocated buffer
  if (len > MAX_PERMUTATIONS_BUFFER_SIZE) return;
  
  unsigned int num_perms = factorial(len);
  if (num_perms <= 1) return;

  strcpy(buffer, str);

  // handle simple cases
  if (len == 1) {
    print_permutation(1, str);
  } else if (len == 2) {
    print_permutation(1, buffer);
    swap(&buffer[0], &buffer[1]);
    print_permutation(2, buffer);
  } else {
    // move into the actual algorithm
    const unsigned int inner_swap_count = 2;
    unsigned int inner_swap_offset = 1;
    unsigned int inner_swap_index = len - 3;
    const unsigned int outer_swap_count = num_perms / len;
    unsigned int outer_swap_index = len - 1;

    unsigned int middle_swap_index = len - 4;
    
    for (unsigned int i = 0; i < num_perms; i++) {
      inner_swap_offset = inner_swap_offset % 3;
      if (inner_swap_index == 0) {
        inner_swap_index = len -3;
      }
      if (i % outer_swap_count == 0) {
        strcpy(buffer, str);
        swap(&buffer[0], &buffer[outer_swap_index--]);
        print_permutation(i + 1, buffer);
        continue;
      } else if (i % 6 == 0) {
        if (middle_swap_index == 0) {
          middle_swap_index = len - 4;
        }

        swap(&buffer[middle_swap_index--], &buffer[inner_swap_index]);
        print_permutation(i + 1, buffer);
        continue;
      } else if (i % inner_swap_count == 0) {
        swap(&buffer[inner_swap_index], &buffer[inner_swap_index + inner_swap_offset]);
        print_permutation(i + 1, buffer);
        continue;
      } 

      swap(&buffer[len - 1], &buffer[len - 2]);
      print_permutation(i + 1, buffer);
    }
  }
}