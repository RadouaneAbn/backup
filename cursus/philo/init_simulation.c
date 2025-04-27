#include "philo.h"


int init_simulation_data(t_table *table)
{
    int status;

    table->philos = malloc(table->number_of_philosophers * sizeof(t_philo));
    if (table->philos == NULL)
        return (1);
    table->forks = malloc(table->number_of_forks * sizeof(pthread_mutex_t));
    if (table->forks == NULL)
    {
        free(table->philos);
        return (1);
    }
    create_philosophers(table);
    status = create_forks(table);
    if (status != 0)
    {
        free(table->philos);
        free(table->forks);
    }
    return (status);
}

int init_simulation(t_table *table)
{
    int status;

    status = init_simulation_data(table);
    table->simulation_running = FALSE;
    if (status != 0)
        return (status);
    return (status);
}
