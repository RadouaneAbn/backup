#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isascii(int c)
{
    int output = ft_isascii(c);
    int original = isascii(c);
    
	printf("the character: %c\n", (char)c);
    printf("isascii   : %d\n", original);
    printf("ft_isascii: %d\n", output);
    
    if (output != original) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
	printf("\n");
}

int main()
{
    test_isascii('A');  // Test uppercase letter
    test_isascii('z');  // Test lowercase letter
    test_isascii('0');  // Test digit
    test_isascii(' ');  // Test space character
    test_isascii('\0'); // Test null character
    test_isascii(127);  // Test DEL character
    test_isascii(128);  // Test out of range (above ASCII)
    test_isascii(-1);   // Test out of range (below ASCII)

    return 0;
}

