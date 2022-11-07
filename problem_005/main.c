#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdint.h>
#include "inc_by_min_pf.h"
#include "uthash.h"
#include "prime_f.h"
#include "../common_lib/track_runtime.h"


// Find common factors to the first N integers
int main()
{
	printf("Welcome to common factors\n");

	struct my_runtime log_rt;
	// Common factors to the first N integers will all share prime
	// factors of primes up to N. Incremeant through integer multiples
	// of the product of all primes up to N until all factors are found 
	find_factors_for_all(10);
	log_rt.start = clock();
	find_factors_for_all(20);
	log_rt.stop = clock();
	printf("method 1: %lf\n", output_runtime(log_rt));

	// Alternatively, we can find the prime factors of each number
	// grab all unique values of those number and then multiply the 
	// number of thsoe. 
	log_rt.start = clock();
	find_pf_for_all(20);
	log_rt.stop = clock();
	printf("method 2: %lf\n", output_runtime(log_rt));

	return 0;
}
