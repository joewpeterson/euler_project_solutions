struct array_track{
	int size;
	int malloc_size;
	int *data;
};

int malloc_prime_fact(int input, int **out_array);
int find_factor (int* mod_factor, int denom, struct array_track *my_arr);

int new_mal_size(struct array_track *my_arr);

int find_pf_for_all(int up_to);
