#include "timer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STARTED 1
#define ENDED		2

#define HAS_STARTED(flags) 	(flags & 		STARTED)
#define HAS_ENDED(flags) 		(flags & 		(STARTED | ENDED))
#define RESET(flags)				(flags &= 	(0x00))
#define START(flags) 				(flags |=		(STARTED)); (flags &= ~(ENDED))
#define END(flags) 					(flags |=		(ENDED))

struct _Timer {
	clock_t start;
	clock_t end;
	char		flags;
};

Timer* _timer_create() {
	Timer* t = malloc(sizeof(Timer));
	memset(t, 0, sizeof(Timer));
	return t;
}

void timer_free(Timer* timer) {
	free(timer);
}

void timer_reset(Timer* timer) {
	timer->start 	= 0;
	timer->end 		= 0;
	RESET(timer->flags);
}

void timer_start(Timer* timer) {
	timer_reset(timer);
	timer->start = clock();
	START(timer->flags);
}

void timer_end(Timer* timer) {
	if (!HAS_STARTED(timer->flags)) {
		printf("timer_end should never be called without a preceding call to timer_start\n");
		exit(-1);
	}
	timer->end = clock();
	END(timer->flags);
}

clock_t timer_get_ellapsed(Timer* timer) {
	if (!HAS_STARTED(timer->flags)) {
		printf("timer_get_ellapsed should never be called without a preceding call to timer_start\n");
		exit(-1);
	}
	clock_t ellapsed = 0;
	if (!HAS_ENDED(timer->flags)) {
		ellapsed = clock() - timer->start;
	} else {
		ellapsed = timer->end - timer->start;
	}

	return ellapsed;
}