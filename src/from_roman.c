/*
  from_roman.c

  stdin: roman numeral as a string (one per line)

  stdout: decimal number that corresponds to stdin (also one per line)

  stderr: if the input is not a proper roman numeral

  Author: André Couto Gimael <acgimael at hotmail dot com>
  Date: January 2019
  License: MPL 2.0
*/
#include <stdlib.h>
#include <stdio.h>

enum {
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000
};

int print_decimal_from_roman(const char *string);

int map_roman_to_value(char input);

int main()
{
	char buffer[256];
	while (fgets(buffer, sizeof(buffer), stdin)) {
		int result = 0;
		result = print_decimal_from_roman(buffer);
		if (result == 0) {
			fprintf(stderr, "Translation failed\n");
		} else {
			fprintf(stdout, "%d\n", result);
		}
	}
	return EXIT_SUCCESS;
}

int print_decimal_from_roman(const char *string)
{
	if (string == NULL) {
		fputs("print_decimal_from_roman: string is null\n", stderr);
		return 0;
	} else if (*string == '\0') {
		fputs("print_decimal_from_roman: string is empty\n", stderr);
		return 0;
	}
	int total = 0;
	int last = map_roman_to_value(string[0]);
	total += last;
	int count = 0;
	for (int i = 1; string[i] != '\0'; ++i) {
		int current = map_roman_to_value(string[i]);
		if (current == -1)
			return 0;
		/* illegal sequences: */
		if (last == V && current == V) { /* VV == X -> nonsense */
			fputs("Illegal sequence VV\n", stderr);
			return 0;
		} else if (last == V && current == X) { /* VX == V -> nonsense */
			fputs("Illegal sequence VX\n", stderr);
			return 0;
		} else if (last == L && current == L) { /* LL == C -> nonsense */
			fputs("Illegal sequence LL\n", stderr);
			return 0;
		} else if (last == L && current == C) { /* LC == L -> nonsense */
			fputs("Illegal sequence LC\n", stderr);
			return 0;
		} else if (last == D && current == M) { /* DM == D -> nonsense */
			fputs("Illegal sequence DM\n", stderr);
			return 0;
		}
		/* those were the illegal sequences */
		if (current == last) {
			count++;
			if (count > 3) {
				fprintf(stderr,
					"print_decimal_from_roman: Number is malformed: %.*s\nThere are more than three of the same symbol in a row\n",
					count, &string[i - count + 1]);
				return 0;
			}
			total += current;
		} else {
			count = 1;
			if (last < current) {
				if (current == M && last != C) {
					fputs("Illegal subtraction: *M where * != C\n", stderr);
					return 0;
				} else if (current == D && last != C) {
					fputs("Illegal subtraction: *D where * != C\n", stderr);
					return 0;
				} else if (current == C && last != X) {
					fputs("Illegal subtraction: *C where * != X\n", stderr);
					return 0;
				} else if (current == L && last != X) {
					fputs("Illegal subtraction: *L where * != X\n", stderr);
					return 0;
				}
				total += current - 2 * last;
			} else {
				total += current;
			}
		}
		last = current;
	}
	return total;
}

int map_roman_to_value(char input)
{
	switch (input) {
	case 'I':
		return I;
	case 'V':
		return V;
	case 'X':
		return X;
	case 'L':
		return L;
	case 'C':
		return C;
	case 'D':
		return D;
	case 'M':
		return M;
	case '\r':
	case '\n':
	case ' ':
		return 0;
	default:
		fprintf(stderr, "map_roman_to_value: WARNING: "
			"mapping char (%c) to value has failed\n",
			input);
		return -1;
	}
}
