/*
  to_roman.c

  stdin: decimal number as a string (one per line)

  stdout: roman numeral that corresponds to stdin (also one per line)

  stderr: if the input does not belong to [1..3999]

  Author: André Couto Gimael <acgimael at hotmail dot com>
  Date: January 2019
  License: MPL 2.0
*/
#include <stdlib.h>
#include <stdio.h>

int print_roman_numeral(FILE *stream, unsigned int input);

int main()
{
	char buffer[256];
	while (fgets(buffer, sizeof(buffer), stdin)) {
		unsigned int input = 0;
		char *end = NULL;
		input = (unsigned int)strtoul(buffer, &end, 10);
		if (end != NULL && *end == '\n') {
			print_roman_numeral(stdout, input);
		} else {
			fprintf(stderr, "input is a malformed number\n");
		}
	}
	return EXIT_SUCCESS;
}

int print_roman_numeral(FILE *stream, unsigned int input)
{
	if (stream == NULL) {
		stream = stdout;
	}

	if (input > 3999u) { /* 3999: MMMCMXCIX */
		fprintf(stderr, "out of range\n");
		return 0;
	}

	switch (input / 1000) {
	case 3:
		fprintf(stream, "M");
		/* fallthrough */
	case 2:
		fprintf(stream, "M");
		/* fallthrough */
	case 1:
		fprintf(stream, "M");
		/* fallthrough */
	}

	switch ((input / 100) % 10) {
	case 9:
		fprintf(stream, "CM");
		break;
	case 8:
		fprintf(stream, "DCCC");
		break;
	case 7:
		fprintf(stream, "DCC");
		break;
	case 6:
		fprintf(stream, "DC");
		break;
	case 5:
		fprintf(stream, "D");
		break;
	case 4:
		fprintf(stream, "CD");
		break;
	case 3:
		fprintf(stream, "C");
		/* fallthrough */
	case 2:
		fprintf(stream, "C");
		/* fallthrough */
	case 1:
		fprintf(stream, "C");
		/* fallthrough */
	}

	switch ((input / 10) % 10) {
	case 9:
		fprintf(stream, "XC");
		break;
	case 8:
		fprintf(stream, "LXXX");
		break;
	case 7:
		fprintf(stream, "LXX");
		break;
	case 6:
		fprintf(stream, "LX");
		break;
	case 5:
		fprintf(stream, "L");
		break;
	case 4:
		fprintf(stream, "XL");
		break;
	case 3:
		fprintf(stream, "X");
		/* fallthrough */
	case 2:
		fprintf(stream, "X");
		/* fallthrough */
	case 1:
		fprintf(stream, "X");
		/* fallthrough */
	}

	switch (input % 10) {
	case 9:
		fprintf(stream, "IX");
		break;
	case 8:
		fprintf(stream, "VIII");
		break;
	case 7:
		fprintf(stream, "VII");
		break;
	case 6:
		fprintf(stream, "VI");
		break;
	case 5:
		fprintf(stream, "V");
		break;
	case 4:
		fprintf(stream, "IV");
		break;
	case 3:
		fprintf(stream, "I");
		/* fallthrough */
	case 2:
		fprintf(stream, "I");
		/* fallthrough */
	case 1:
		fprintf(stream, "I");
		/* fallthrough */
	}

	fprintf(stream, "\n");
	return 1;
}
