#include <stdio.h>

int main() {
    char *n = NULL;
    char *s = "red";

    printf("[%5d]\n", 42); // left padding with 5
    printf("[%-3d]\n", 42); // right padding with 5

    printf("[%.5d]\n", 42); // left padding with 5 (filled with 0)
    printf("[%5d]\n", 42); // left padding with 5 (filled with ' ')

    printf("[%x]\n", 42);
    printf("[%#x]\n", 42); // adds 0x before the hexa number

    printf("[%+d]\n", 42); // prints the sign -/+

    printf("[% d]\n", 42); // prints space instead of the + sign
    printf("[% d]\n", -42); // prints the - sign

    // `-`: left justify (right padding)
    // `0`: pad with 0
    // `.`: precision for number (float / int(minimum digits))
    // `#`: alternative format (hex: 0x)
    // `+`: always show the sign
    // ` `: show leading space for positive integers
}