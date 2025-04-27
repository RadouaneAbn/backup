#include "philo.h"

void create_philosophers(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        table->philos[i].id = i + 1;
        table->philos[i].last_meal = 0;
        table->philos[i].state = THINKING;
        table->philos[i].table = table;
        i++;
    }
}

void destroy_forks(t_table *table, int last_fork)
{
    int i;

    i = 0;
    while (i < last_fork)
    {
        pthread_mutex_destroy(&(table->forks[i]));
        i++;
    }
}

int create_forks(t_table *table)
{
    int i;
    int mutex_status;

    i = 0;
    mutex_status = 0;
    while (i < table->number_of_forks)
    {
        mutex_status = pthread_mutex_init(&(table->forks[i]), NULL);
        if (mutex_status != 0)
        {
            printf("mutex init has failed\n");
            destroy_forks(table, i);
            break;
        }
        i++;
    }
    return (mutex_status != 0);
}
