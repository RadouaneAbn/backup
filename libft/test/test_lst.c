#include "libft.h"
#include <stdio.h>

void    del(void *d)
{
    free(d);
}

void    ft_double(void *n) {
    *(int *)n = *(int *)n * 2; 
}

void    *ft_mult(void *n) {
    int *nn = malloc(sizeof(int));
    *nn = *(int *)n * 10;
    return (nn);
}

void    free_int(void *n) {
    free(n);
}


int main() {
    t_list *head = NULL;
    t_list *current = NULL;
    int s1 = 2;
    int s2 = 4;
    int s3 = 6;
    int s4 = 8;
    int s5 = 0;

    head = NULL;

    t_list *node1 = ft_lstnew(&s1);
    t_list *node2 = ft_lstnew(&s2);
    t_list *node3 = ft_lstnew(&s3);
    t_list *node4 = ft_lstnew(&s4);
    t_list *node5 = ft_lstnew(&s5);

    ft_lstadd_back(&head, node5);
    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);
    ft_lstadd_back(&head, node4);

    current = head;
    while (current) {
        printf("%d\n", *(int *) current->content);
        current = current->next;
    }

    printf("** The size of the list is: %d\n\n", ft_lstsize(head));
    printf("the head is: %d\n", *(int *) head->content);
    t_list *last_node = ft_lstlast(head);
    printf("The tail is: %d\n", *(int *) last_node->content);

    ft_lstiter(head, ft_double);
    printf("\nprint after iter (n x 2):\n");
    current = head;
    while (current) {
        printf("%d\n", *(int *) current->content);
        current = current->next;
    }

    t_list  *new_head = ft_lstmap(head, ft_mult, NULL);
    printf("\nprint after map (n x 10): \n");
    current = new_head;
    while (current) {
        printf("%d\n", *(int *) current->content);
        current = current->next;
    }


    ft_lstclear(&head, NULL);
    ft_lstclear(&new_head, free_int);
    return (0);
}