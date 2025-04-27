#include "philo.h"

/*
    3
*/

static int validate_args(t_table *table)
{
    int status;

    status = 0;
    if (table->number_of_philosophers <= 0)
        status += printf(PHILO_N_ERROR_MSG);
    if (table->time_to_die <= 0)
        status += printf(TIME_TO_DIE_ERROR_MSG);
    if (table->time_to_eat <= 0)
        status += printf(TIME_TO_EAT_ERROR_MSG);
    if (table->time_to_sleep <= 0)
        status += printf(TIME_TO_SLEEP_ERROR_MSG);
    return ((status != 0) * (-1));
}

int convert_arguments(t_table *table, int ac , char **av)
{
    table->number_of_philosophers = ft_atoi(av[1]);
    table->number_of_forks = table->number_of_philosophers;
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        table->must_eat_meals_count = ft_atoi(av[5]);
    return (validate_args(table));
}