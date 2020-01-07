# Multiples of 3 and 5

## C Solution

The [C solution](c/) tries to minimize time and space complexity by keeping a rolling sum only and going through both the 3 multiples and 5 multiples as it progresses.
The sum type was chosen with foreknowledge of the answer and would overflow if the problem space was changed to try that.

To run:

	make
	./sum_multiples_less_than_max 1000 3 5

Example output:

	The sum of all the unique multiples of 3 and 5 below 1000 is: 233168

## Python Solution

The [Python solution](python/) is a [code golf](https://en.wikipedia.org/wiki/Code_golf) approach that only uses 41 characters (excluding print statement)

To run:

	./run.sh

Example output:

	233168
