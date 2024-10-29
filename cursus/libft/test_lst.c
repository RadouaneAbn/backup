#include "libft.h"
#include <stdio.h>

void    del(void *d)
{
    free(d);
}

int main() {
    t_list *head = NULL;
    t_list *current = NULL;
    t_list *tmp = NULL;
    char *s1 = "test 1";
    char *s2 = "test 2";
    char *s3 = "test 3";
    char *s4 = "test add last";
    char *s5 = "test add last at start";

    head = NULL;

    t_list *node1 = ft_lstnew(s1);
    t_list *node2 = ft_lstnew(s2);
    t_list *node3 = ft_lstnew(s3);
    t_list *node4 = ft_lstnew(s4);
    t_list *node5 = ft_lstnew(s5);

    ft_lstadd_back(&head, node5);
    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);
    ft_lstadd_back(&head, node4);

    current = head;
    while (current) {
        printf("%s\n", (char *) current->content);
        current = current->next;
    }

    printf("** The size of the list is: %d\n\n", ft_lstsize(head));
    printf("the head is: %s\n", (char *) head->content);
    t_list *last_node = ft_lstlast(head);
    printf("The tail is: %s\n", (char *) last_node->content);

    ft_lstclear(&head, NULL);
    return (0);
}