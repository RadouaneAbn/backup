#include "../includes/utils.h"

void add_to_queue(t_queue *q, void *data)
{
    t_list *node;

    node = ft_lstnew(data);
    if (node == NULL)
        return;
    if (q->head == NULL)
        q->head = node;
    else
        q->tail->next = node;
    q->tail = node;
    if (q->is_empty == TRUE)
        q->is_empty = FALSE;
}

void *pop_from_queue(t_queue *q)
{
    t_list *node;
    void *data;

    if (q->head == NULL)
        return (NULL);
    node = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    data = node->content;
    free(node);
    if (q->head == NULL)
        q->is_empty = TRUE;
    return (data);
}


t_queue *create_queue()
{
    t_queue *queue;

    queue = malloc(sizeof(t_queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->is_empty = TRUE;
}

// int main()
// {
//     t_queue *queue;

//     queue = create_queue();
//     int i = 0, j = 1, k = 2, l = 3;

//     add_to_queue(queue, &i);
//     add_to_queue(queue, &j);
//     add_to_queue(queue, &k);
//     add_to_queue(queue, &l);

//     int tmp;
//     while (queue->is_empty == FALSE)
//     {
//         tmp = *( int * )pop_from_queue(queue);
//         printf("%d\n", tmp);
//     }

//     free(queue);
//     return (0);
// }