#include "track_runtime.h"
#include <time.h>

double output_runtime(struct my_runtime timer)
{
	return ((double)(timer.stop - timer.start) / CLOCKS_PER_SEC);
}
