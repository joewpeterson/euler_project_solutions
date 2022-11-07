#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>



//What are we going to do? Prime factor needs a number input
struct array_track{
	int size;
	int malloc_size;
	int *data;
};

int new_mal_size(struct array_track *my_arr)
{
	if (my_arr->size < my_arr->malloc_size)
		return 0;

	while(my_arr->size > my_arr->malloc_size)
		my_arr->malloc_size *= 2;

	my_arr->data= realloc(my_arr->data, my_arr->malloc_size*sizeof(int));
	return 1;
}

int find_factor (int* mod_factor, int denom, struct array_track *my_arr)
{
	int rv = 0;
	while (*mod_factor % denom == 0) {
		*mod_factor /= denom;
		rv++;
	}

	if (!rv)
		return 0;

	int orig_size = my_arr->size;
	my_arr->size += rv;
	new_mal_size(my_arr);

	int *insert_loc = &my_arr->data[orig_size];
	for (int i = 0; i < rv; i++){
		*insert_loc = denom;
		insert_loc += 1;
	}

	return 0;
}

int malloc_prime_fact(int input, int **out_array)
{

	struct array_track my_arr;

	my_arr.size = 0;
	my_arr.malloc_size = 5;
	my_arr.data = malloc(my_arr.malloc_size*sizeof(int));

	// Find factors of 2
	find_factor (&input, 2, &my_arr);

	// Find odd factors up to srqt of input
	for (int i = 3; i <= sqrt(input); i+=2)
		find_factor(&input, i, &my_arr);

	// print the last prime factor
	if (input > 2) 
		find_factor(&input, input, &my_arr);

	*out_array = my_arr.data;
	return my_arr.size;
}

int update_pf_list(int *track_all, int i, int up_to)
{
	int *track_local = calloc(up_to , sizeof(int));
	
	int *test;
	int size = malloc_prime_fact(i, &test);

	for(int j = 0; j < size; j++){
		track_local[test[j] - 1]++;
	}
	free(test);

	for(int j = 0; j < up_to; j++){
		if (track_local[j] > track_all[j])
			track_all[j] = track_local[j];
	}
	free(track_local);

	return 0;
}

int multipy_parts(int *track_all, int up_to)
{
	int total = 1;
	for (int i = 0; i < up_to; i++){
		if (track_all[i]){
			for (int j = 0; j < track_all[i]; j++)
				total *= (i+1);
		}
	}
	return total;
}

int find_pf_for_all(int up_to)
{
	int *track_all = calloc(up_to , sizeof(int));

	for (int i = 2; i <= up_to; i++){
		update_pf_list(track_all, i, up_to);
	}


	printf("New method: %d\n", multipy_parts( track_all, up_to));

	free(track_all);
	
	return 0;
}
