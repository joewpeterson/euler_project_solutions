#include <stdio.h>

// Compute the sum of the even Fibonacci numbers up so long as the number
// is even

int is_odd(int i);

int main()
{
	size_t total_sum = 0;
	int fib_last = 0;
	int fib_current = 1;

	// Using straight O(N) method for fib calculation
	int count = 1;
	while(1){
		int temp = fib_current;
		fib_current += fib_last;	
		fib_last = temp;
		count++;

		if(!is_odd(fib_current))
			total_sum += fib_current; 

		if (fib_current > 4000000)
			break;
	}

	printf("Sum of all even valued Fibonacci numbers < 4 million: %d\n",
		total_sum);

	return 0;
}

int is_odd(int i)
{
	return (i & 1);
}
