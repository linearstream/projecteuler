/* File: multiples_3_5.c
 * Author: Joshua Thies
 * Description: Sum the uniq multiples of 3 and 5 less than 100
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "multiples_3_5.h"

#define BASE 10
#define REQD_ARG_CNT 4
#define MAX_IDX 1
#define A_IDX 2
#define B_IDX 3

struct Args {
	int max, a, b;
};

// main:
//   Accepts CLI arguments and runs the program
int main(int argc, char *argv[]) {
	int errno = 0;
	// TODO: allow for an array of numbers instead of just two (a, b)
    struct Args args = parse_args(argc, argv);
	if (args.max == -1) {
		errno = 2;
	} else {
		report_sum(args.a, args.b, args.max,
			sum_multiples_less_than_max(args.a, args.b, args.max));
	}
	return errno;
}

static struct Args parse_args(int argc, char *argv[]){
	struct Args args;
	if (argc < REQD_ARG_CNT) {
		fprintf(stderr, "ERROR: Incorrect number of parameters given (%d)."
			"Must specify: max a b\n", REQD_ARG_CNT-1);
		args.max = args.a = args.b = -1;
	} else {
		args.max = strtoi(argv[MAX_IDX]);
		args.a = strtoi(argv[A_IDX]);
		args.b = strtoi(argv[B_IDX]);
	}
	return args;
}

// Convert the string at str to an integer
static int strtoi(char* str) {
	return (int) strtol(str, (char **)NULL, BASE);
}

int sum_multiples_less_than_max(int a, int b, int max){
	int sum, current, current_a, current_b;
	sum = current = current_a = current_b = 0;
	// current: Variable for stepping by a or b when appropriate
	while (current < max) {
			sum += current;
			// Increment current_* by iter_* when current_* <= current
			current_a = conditional_incr(current_a, current, a);
			current_b = conditional_incr(current_b, current, b);
			current = lesser_of(current_a, current_b);
	}
	return sum;
}

// Returns counter + step if counter <= compare; otherwise, return counter
static int conditional_incr(int counter, int compare, int step){
	return counter <= compare ? counter+step : counter;
}

static int lesser_of(int a, int b){
	return a < b ? a : b;
}

void report_sum(int a, int b, int max, int sum){
	printf("The sum of all the unique multiples of %d and %d below %d is: "
		"%d\n", a, b, max, sum);
}
