#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isalpha(char c)
{
    int output = ft_isalpha(c);
    int original = isalpha(c);
    printf("isalpha   : %d\n", original);
    printf("ft_isalpha: %d\n", output);
    if ((output == 0 && original != 0) || (output != 0 && original == 0)) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_isalpha('c');
    test_isalpha('Z');
    test_isalpha('5');
    test_isalpha('!');
    test_isalpha(' ');
    test_isalpha('\x80');

    return 0;
}
