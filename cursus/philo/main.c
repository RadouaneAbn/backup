#include "philo.h"


/**
 * Input example:
 *  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
*/

void *run_simulation_thread(void *args)
{
    t_philo *philo;

    philo = (t_philo *) args;
    while (philo->table->simulation_running == FALSE)
        ;
    while (philo->table->simulation_running)
    {
        
    }
    return (NULL);
}

int create_threads_for_philosophers(t_table *table) 
{
    int status;
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        status = pthread_create(&(table->philos[i].philo), NULL, run_simulation_thread, NULL);
        if (status != 0)
        {
            printf("pthread_create[%d] failed\n", i);
            break;
        }
        i++;
    }
    return (status);
}

int join_threads(t_table *table)
{
    int i;
    int status;

    i = 0;
    status = 0;
    while (i < table->number_of_philosophers)
    {
        status += pthread_join(table->philos[i].philo, NULL);
        if (status != 0)
        printf("pthread_join[%d] failed\n", i);
        i++;
    }
    table->simulation_running = TRUE;
    return (status);
}

int start_simulation(t_table *table)
{
    int status;

    status = create_threads_for_philosophers(table);
    if (status == 0)
        status += join_threads(table);
    return (status);
}

int main(int ac, char **av)
{
    t_table table;
    int status;

    if (ac > 6 || ac < 5)
    {
        printf(USAGE_ERROR_MSG, av[0]);
        return (1);
    }
    memset(&table, 0, sizeof(t_table));
    status = convert_arguments(&table, ac, av);
    printf("convert_arguments: %d\n", status);
    if (status == 0)
        status = init_simulation(&table);
    printf("init_simulation: %d\n", status);
    if (status == 0)
        status = start_simulation(&table);
    printf("start_simulation: %d\n", status);
    return (status);
}