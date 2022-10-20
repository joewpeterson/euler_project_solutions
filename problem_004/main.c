#include <stdio.h>
#include <math.h>
#include <stdint.h>

#include "main.h"

int main()
{
	int starter = 999;

	// Find a 6 digit palindromic number, starting from the largest
	for (int i = starter; i > 100; i--){
		int j = find_reverse(i);
		
		int pal = i * 1000 + j;;

		int f1 = 0;
		int f2 = 0;
		if(three_digit_factors(pal, &f1, &f2)){
			printf("found! %d is product of  %d %d\n", pal, f1, f2);
			break;	
		}

		
	}

	return 0;
}

int three_digit_factors(int pal, int *f1, int *f2)
{
	*f2 = sqrt(pal) - 2;

	for (*f1 = sqrt(pal) + 2; *f1 > 100; (*f1)--){
		int product = (*f2) * (*f1);
		while ((product < pal) && *f2 < 1000 && *f1 < 1000){
			(*f2)++;	
			product = (*f2) * (*f1);
		}
		
		if (product == pal)
			return 1;
	}
	return 0;
}


int find_reverse(int i)
{
	int rev = 0;
	while (i != 0){
		int r = i % 10;
		rev = rev * 10  + r;
		i /= 10;
	}
	return rev;
}
