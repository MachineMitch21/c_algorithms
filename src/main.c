#include <stdio.h>
#include <string.h>
#include "str_permutations.h"

int main(int argc, char** argv) {
  if (argc > 1) {
    max_permutations(argv[1]);
  } else {
    max_permutations("cat");
  }
  return 0;
}