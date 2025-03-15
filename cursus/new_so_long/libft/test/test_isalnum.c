#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isalnum(int c)
{
    int output = ft_isalnum(c);
    int original = isalnum(c);
    
    printf("isalnum   : %d\n", original);
    printf("ft_isalnum: %d\n", output);
    
    if ((output == 0 && original != 0) || (output != 0 && original == 0)) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_isalnum('0');  // Test digit
    test_isalnum('5');  // Test digit
    test_isalnum('A');  // Test uppercase letter
    test_isalnum('z');  // Test lowercase letter
    test_isalnum('@');  // Test special character
    test_isalnum(' ');  // Test space character
    test_isalnum('\0'); // Test null character
    test_isalnum(256);  // Test out of range
    test_isalnum('!');  // Test special character

    return 0;
}

