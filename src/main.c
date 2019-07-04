#include <stdio.h>
#include <string.h>

#include "str_permutations.h"
#include "timer.h"

Timer* timer;

void str_permutations_driver(char* str) {
	timer_start(timer);
	max_permutations(str);
	timer_end(timer);
	printf("My non recursive permute func took %d ms\n", timer_get_ellapsed(timer));
	timer_start(timer);
	max_permutations_recursive(str, 0, strlen(str) - 1);
	timer_end(timer);
	printf("Recursive permute func took %d ms\n", timer_get_ellapsed(timer));
	timer_reset(timer);
}

int main(int argc, char** argv) {
	timer = _timer_create();
  if (argc > 1) {
    str_permutations_driver(argv[1]);
  } else {
    str_permutations_driver("cat");
  }
	timer_free(timer);
  return 0;
}