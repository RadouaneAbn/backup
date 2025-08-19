#include "philo_bonus.h"

static bool validate_args(t_table *table, int ac)
{
    if (table->options.total_philos < 0 || table->options.total_philos > 200)
        return (false);
    if (table->options.time2die <= 0)
        return (false);
    if (table->options.time2eat <= 0)
        return (false);
    if (table->options.time2sleep <= 0)
        return (false);
    if (ac == 6 && table->options.max_meals < 0)
        return (false);
    return (true);
}

bool convert_arguments(t_table *table, int ac , char **av)
{
    if (ft_atoi(av[1], &(table->options.total_philos)) == false)
        return (false);
    // printf("Total philosophers: %d\n", table->options.total_philos);
    table->options.total_forks = table->options.total_philos;
    if (ft_atoi(av[2], &(table->options.time2die)) == false)
        return (false);
    // printf("time2die: %d\n", table->options.time2die);
    if (ft_atoi(av[3], &(table->options.time2eat)) == false)
        return (false);
    // printf("time2eat: %d\n", table->options.time2eat);
    if (ft_atoi(av[4], &(table->options.time2sleep)) == false)
        return (false);
    // printf("time2sleep: %d\n", table->options.time2sleep);
    if (ac == 6)
    {
        if (ft_atoi(av[5], &(table->options.max_meals)) == false)
            return (false);
        // printf("max_meals: %d\n", table->options.max_meals);
    }
    else
        table->options.max_meals = -1;
    if (validate_args(table, ac) == false)
        return (false);
    return (true);
}