#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isdigit(int c)
{
    int output = ft_isdigit(c);
    int original = isdigit(c);
    
    printf("isdigit   : %d\n", original);
    printf("ft_isdigit: %d\n", output);
    
    if ((output == 0 && original != 0) || (output != 0 && original == 0)) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_isdigit('0'); // Test digit
    test_isdigit('5'); // Test digit
    test_isdigit('9'); // Test digit
    test_isdigit('a'); // Test lowercase letter
    test_isdigit('Z'); // Test uppercase letter
    test_isdigit('!'); // Test special character
    test_isdigit(' '); // Test space character
    test_isdigit('\0'); // Test null character
    test_isdigit(256); // Test out of range

    return 0;
}

