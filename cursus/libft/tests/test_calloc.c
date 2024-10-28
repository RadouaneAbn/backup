#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
void *ft_calloc(size_t count, size_t size);

void print_memory(const void *ptr, size_t size) {
    const unsigned char *mem = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", mem[i]);
    }
    printf("\n");
}

int main() {
    size_t count1 = 5, size1 = sizeof(int);
    int *arr1 = (int *)ft_calloc(count1, size1);
    assert(arr1 != NULL);
    printf("Test 1: Allocate %zu integers\n", count1);
    print_memory(arr1, count1 * size1);

    for (size_t i = 0; i < count1; i++) {
        assert(arr1[i] == 0);
    }
    free(arr1);

    size_t count2 = 10, size2 = sizeof(char);
    char *arr2 = (char *)ft_calloc(count2, size2);
    assert(arr2 != NULL);
    printf("Test 2: Allocate %zu characters\n", count2);
    print_memory(arr2, count2 * size2);

    for (size_t i = 0; i < count2; i++) {
        assert(arr2[i] == 0);
    }
    free(arr2);

    size_t count3 = 0, size3 = sizeof(int);
    int *arr3 = (int *)ft_calloc(count3, size3);
    assert(arr3 != NULL);
    printf("Test 3: Allocate 0 elements, ptr = %p\n", (void *)arr3);
    free(arr3);

    size_t count4 = 1000000, size4 = sizeof(double);
    double *arr4 = (double *)ft_calloc(count4, size4);
    assert(arr4 != NULL);
    printf("Test 4: Allocate %zu doubles\n", count4);
    print_memory(arr4, 10 * sizeof(double));

    for (size_t i = 0; i < 10; i++) {
        assert(arr4[i] == 0.0);
    }
    free(arr4);

    size_t count5 = SIZE_MAX / 2 + 1;
    size_t size5 = 2;
    void *arr5 = ft_calloc(count5, size5);
    assert(arr5 == NULL);
    printf("Test 5: Allocate with potential overflow, ptr = %p (should be NULL)\n", arr5);

    printf("All tests passed!\n");
    return 0;
}

