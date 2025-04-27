#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    usleep(1000);
    printf("test\n");
    return 0;
}
