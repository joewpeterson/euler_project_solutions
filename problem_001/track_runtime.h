
#include <time.h>

#ifndef TRACK_RUNTIME_H
#define TRACK_RUNTIME_H

struct my_runtime
{
	clock_t start;
	clock_t stop;
};

double output_runtime(struct my_runtime timer);

#endif //TRACK_RUNTIME_H
