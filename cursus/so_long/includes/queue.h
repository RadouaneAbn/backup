#ifndef QUEUE_H
#define QUEUE_H

#include "../includes/utils.h"

void add_to_queue(t_queue *q, void *data);
void *pop_from_queue(t_queue *q);
t_queue *create_queue();

#endif