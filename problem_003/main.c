#include <stdio.h>
#include <math.h>
#include <stdint.h>

#include "main.h"

// In this problem we find the prime factors of the number
// 600851475143

#define NUM_TO_FIND 600851475143

int main()
{
	printf("Hello prime factor\n");
	find_prime_fact(NUM_TO_FIND);
	
	return 0;
}

// Print all the whole factors of mod_factor by denom. Modify mod_factor
// by all the whole denom factors which divide evenly into mod_factor
void reduce_and_print (uint64_t* mod_factor, int denom)
{
	while (*mod_factor % denom == 0) {
		*mod_factor /= denom;
		printf("%d ", denom);
	}
}

void find_prime_fact(uint64_t input)
{
	// Find factors of 2
	reduce_and_print (&input, 2);

	// Find odd factors up to srqt of input
	for (int i = 3; i <= sqrt(input); i+=2)
		reduce_and_print(&input, i);

	// print the last prime factor
	if (input > 2) 
		printf("%lld", input);
	printf("\n");

}
