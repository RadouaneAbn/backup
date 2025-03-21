#include "so_long.h"

t_direction *create_direction(int dir)
{
    t_direction *node;

    node = ft_smalloc(sizeof(t_direction));
    if (node == NULL)
        exit_error(1, MALC_MGS);
    node->next = NULL;
    node->direction = dir;
    return (node);
}

int direction_is_listed(t_direction *head, int dir)
{
    while (head)
    {
        if (head->direction == dir)
            return (TRUE);
        head = head->next;
    }
    return (FALSE);
}

int *keys_count()
{
    static int count;

    return (&count);
}

void inc_count()
{
    (*keys_count())++;
    printf("count %d\n", *keys_count());
}

void dec_count()
{
    (*keys_count())--;
    printf("count %d\n", *keys_count());
}

void pop_key(t_game *game, t_direction **head, int direction)
{
    t_direction *current;
    t_direction *prev;

    current = *head;
    prev = NULL;
    while (current)
    {
        if (current->direction == direction)
            break;
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return ;
    if (prev == NULL)
        *head = (*head)->next;
    else
        prev->next = current->next;
    if (*head == NULL)
    {
        game->entities.player.last_direction = current->direction;
        game->entities.player.state = IDLE;
    }
    else
        game->entities.player.state = MOVING;
    free(current);
}

void append_key(t_game *game, t_direction **head, int direction)
{
    t_direction *new_dir;

    game->entities.player.state = MOVING;
    if (direction_is_listed(*head, direction) == TRUE)
        return ;
    new_dir = create_direction(direction);
    if (*head == NULL)
        *head = new_dir;
    else
    {
        new_dir->next = *head;
        *head = new_dir;
    }
}

// void startup_key(t_game *game, t_direction **head, int direction)
// {
//     t_direction *new_dir;

//     new_dir = create_direction(direction);
//     new_dir->next = *head;
//     *head = new_dir;
// }