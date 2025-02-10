#include <stdio.h>
#include <string.h>
#include <assert.h>

int ft_memcmp(const void *s1, const void *s2, size_t n);

int main() {
    char buf1[] = "Hello";
    char buf2[] = "Hello";
    assert(memcmp(buf1, buf2, 5) == ft_memcmp(buf1, buf2, 5));

    char buf3[] = "Hello";
    char buf4[] = "Helxo";
    assert(memcmp(buf3, buf4, 5) == ft_memcmp(buf3, buf4, 5));

    char buf5[] = "Hello";
    char buf6[] = "Hellx";
    assert(memcmp(buf5, buf6, 5) == ft_memcmp(buf5, buf6, 5));

    char buf7[] = "Hello";
    char buf8[] = "Hellx";
    assert(memcmp(buf7, buf8, 4) == ft_memcmp(buf7, buf8, 4));

    char buf9[] = "Short";
    char buf10[] = "Shorter";
    assert(memcmp(buf9, buf10, 5) == ft_memcmp(buf9, buf10, 5));

    char buf11[] = {'A', 'B', '\0', 'D', 'E'};
    char buf12[] = {'A', 'B', '\0', 'C', 'E'};
    assert(memcmp(buf11, buf12, 5) == ft_memcmp(buf11, buf12, 5));

    char buf13[] = "";
    char buf14[] = "";
    int res = memcmp(buf13, buf14, 0);
    int ft_res = ft_memcmp(buf13, buf14, 0);
    assert(res == ft_res);

    char buf15[] = "abcde";
    char buf16[] = "zbcde";
    assert(memcmp(buf15, buf16, 5) == ft_memcmp(buf15, buf16, 5));

    char buf17[1000], buf18[1000];
    memset(buf17, 'A', 1000);
    memset(buf18, 'A', 999);
    buf18[999] = 'B';
    assert(memcmp(buf17, buf18, 1000) == ft_memcmp(buf17, buf18, 1000));

    printf("All tests passed!\n");
    return 0;
}

