#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];
    
    if (pipe(fd) == -1)
        return (1);
    
    int id = fork();

    if (id == 0)
    {
        start = 0;
        end = arr_size / 2;
    } else {
        start = arr_size / 2;
        end = arr_size;
    }

    int sum = 0;
    int i = start;

    while (i < end)
        sum += arr[i++];
    
    printf("Sum: %d\n", sum);
    

    if (id == 0) {
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    } else {
        int comming_sum;
        close(fd[1]);
        read(fd[0], &comming_sum, sizeof(comming_sum));
        close(fd[0]);
        wait(NULL);
        sum += comming_sum;
        printf("Total sum: %d\n", sum);
    }

}