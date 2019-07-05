#ifndef TIMER_H
#define TIMER_H

#include <time.h>

typedef struct _Timer Timer;

Timer* _timer_create();
void timer_free(Timer* timer);
void timer_reset(Timer* timer);
void timer_start(Timer* timer);
void timer_end(Timer* timer);
clock_t timer_get_ellapsed(Timer* timer);

#endif // TIMER_H