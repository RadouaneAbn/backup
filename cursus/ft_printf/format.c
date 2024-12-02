#include <stdio.h>

int	main(void)
{
	char *n = NULL;
	char *s = "red";

	// printf("[%5d]\n", 42); // left padding with 5
	// printf("[%-5d]\n", 42); // right padding with 5

	// printf("[%.5d]\n", 42); // left padding with 5 (filled with 0)

	printf("[%#015x]\n", 42);
	printf("[%-#15x]\n", 42);
	printf("[%-15d]\n", 42);
	printf("[%x]\n", 42);
	printf("[%5c]\n", 'a');
	return (0);
	// printf("[%#x]\n", 42); // adds 0x before the hexa number

	// printf("[%+d]\n", 42); // prints the sign -/+

	// printf("[% d]\n", 42); // prints space instead of the + sign
	// printf("[% d]\n", -42); // prints the - sign

	// printf("% u\n", 0);
	// printf("%+u\n", 0);

	// printf("[%5.d]\n", 42);     // [   42]
	// printf("[%5.4d]\n", 42);     // [00042]
	// printf("[%5d]\n", 42);      // [   42]
	// printf("[% .5d]\n", 42);    // [ 00042]
	// printf("[%+.5d]\n", 42);    // [+00042]
	// printf("[%.5%]\n", 42);    // [%]
	// printf("[% -+5d]\n", 42);    // [%]
	// printf("[%.5d]\n", 42); //

	// `-`: left justify (right padding)
	// `0`: pad with 0 & get ignored with '-'
	// `.`: precision for number (float / int(minimum digits))
	// `#`: alternative format (hex: 0x)
	// `+`: always show the sign
	// ` `: show leading space for positive integers
}