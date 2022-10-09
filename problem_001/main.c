#include<stdio.h>
#include<time.h>

#include "main.h"
#include "track_runtime.h"

#define SUM_BELOW 10000

int main()
{
	int total;
	struct my_runtime timer;

	timer.start = clock();
	total = sum_of_xs_up_to_y(3, SUM_BELOW);
	total += sum_of_xs_up_to_y(5, SUM_BELOW);
	total -= sum_of_xs_up_to_y(15, SUM_BELOW);
	timer.stop = clock();

	printf("Sum: %d\n", total);
	printf("Time for O(N) routine: %lf\n\n", output_runtime(timer) );

	total = 0;
	timer.start = clock();
	total += gauss_trick( 3, SUM_BELOW);
	total += gauss_trick( 5, SUM_BELOW);
	total -= gauss_trick( 15, SUM_BELOW);
	timer.stop = clock();

	printf("Sum: %d\n", total);
	printf("Time for O(1) routine: %lf\n\n", output_runtime(timer) );

	return 0;
}

int sum_of_xs_up_to_y(int interval, int up_to)
{
	int sum = 0;

	for ( int i = interval; i < up_to; i+=interval)
		sum += i;	

	return sum;
}

int is_odd(int check)
{
	return (check & 1);
}

int gauss_trick(int interval, int up_to)
{
	up_to--;

	int num_intervals;
	num_intervals = up_to / interval;

	up_to = num_intervals * interval;
	
	if (is_odd(num_intervals))
		num_intervals++;
	else
		up_to += interval;

	return ((num_intervals / 2) * up_to);
}

