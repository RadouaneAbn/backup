#include <stdio.h>

/**
 * In this file a simple implementation of a circular indexing
 */

#define ARR_SIZE 10

typedef struct s_stack
{
    int arr[ARR_SIZE];
    int front;
    int rear;
    int size;
} t_stack;


void print_circle(t_stack stack) {
    int i = 0;

    while (i < stack.size) {
        printf("%3d\n", stack.arr[(i + stack.front) % ARR_SIZE]);
        i++;
    }
}

void push(int n, t_stack *stack) {
    stack->arr[(stack->rear % ARR_SIZE)] = n;
    stack->rear = (stack->rear + 1) % 10;
    stack->size++;
}

void pop(t_stack *stack) {
    stack->size--;
    stack->front = (stack->front + 1) % 10;
}

int main() {
    // int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t_stack stack = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 7, 10, 3};

    print_circle(stack);

    printf("\n1 push\n");
    push(15, &stack);

    print_circle(stack);

    printf("\n3 push\n");
    push(200, &stack);
    push(900, &stack);
    push(655, &stack);
    push(888, &stack);

    print_circle(stack);

    printf("\n3 pop\n");

    pop(&stack);
    pop(&stack);
    pop(&stack);
    print_circle(stack);
}