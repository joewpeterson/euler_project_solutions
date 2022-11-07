#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdint.h>
#include "inc_by_min_pf.h"

#define PRIME_LIST_SIZE 8

// Find the min increment for max. Take product of all 
// primes up to max (limited by the first PRIME_LIST_SIZE primes)
size_t prime_inc( int max )
{
	int pm_list[PRIME_LIST_SIZE] = {2,3,5,7,11,13,17,19};
	int *prime_list = pm_list;

	size_t rv = 1;
	for (int i = 0; i < PRIME_LIST_SIZE; i++){
		if (*prime_list > max)
			break;
		rv *= *prime_list;
		prime_list += 1;
	}

	return rv;
}

void find_factors_for_all(int up_to)
{
	size_t common_factor = up_to;
	size_t inc_val =  prime_inc(up_to);
	while (1){
		if(!inc_common_factor(&common_factor, up_to, inc_val))
			break;
	}
	printf("found common up to %d: %d\n", up_to, common_factor);

}

// Find the next possible common factor to all values between 1 and up_to
// return non zero if answer not yet found return 0 once common factor found 
size_t inc_common_factor(size_t *common_out, int up_to, size_t inc_val)
{
	if (inc_val > *common_out)
		*common_out =  inc_val;

	int residual;	
	for (int i = up_to; i > 1; i--){
		residual = (*common_out) % i;

		// As soon as we find an instance where residual is not zero
		// advance by an amount which will make this and the biggest
		// factor residual remain at 0; 
		if (residual){
			*common_out +=  inc_val;
			return residual;
		}
		
	}
	return 0;
}
