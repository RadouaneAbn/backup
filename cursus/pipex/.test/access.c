#include "header.h"

void check(int fd)
{
    if (fd == -1)
        perror("");
}

int main() {
    int fd;
    
    printf("$>File does not exist:\n");
    check(access("files/file_does_not_exist.txt", F_OK));

    printf("\n$>File exist:\n");
    check(access("files/file_exists.txt", F_OK));

    printf("\n$>Non readable file:\n");
    check(access("files/non_readable_file.txt", R_OK));

    printf("\n$>Readable file:\n");
    check(access("files/readable_file.txt", R_OK));

    printf("\n$>Non writable file:\n");
    check(access("files/non_writable_file.txt", W_OK));

    printf("\n$>Writable file:\n");
    check(access("files/writable_file.txt", W_OK));

    printf("\n$>Non executable file:\n");
    check(access("files/non_executable_file.txt", X_OK));

    printf("\n$>Executable file:\n");
    check(access("files/executable_file.txt", X_OK));
}