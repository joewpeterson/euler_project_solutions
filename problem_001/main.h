
#ifndef MAIN_H
#define MAIN_H

// Order (N) routine for finding the sum of all ints from 0 to up_to (not 
// inclding up_to) with factors of interval.
int sum_of_xs_up_to_y(int interval, int up_to);

// Bitwise check of int to determain if it is odd
// Return true if int is odd, false otherwise
int is_odd(int check);

// Order (1) routine for finding the sum of all ints from 0 to up_to (not 
// inclding up_to) with factors of interval.
int gauss_trick(int interval, int up_to);

#endif //MAIN_H
