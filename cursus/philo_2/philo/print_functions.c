#include "philo.h"

size_t get_time_passed(t_philo *philo)
{
	return (get_current_time() - philo->options->start_time);
}

void print_message(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&(philo->options->console_lock));
    if (sim_is_running(philo) == true)
        printf("%zu %d %s\n", get_time_passed(philo), philo->id, msg);
    pthread_mutex_unlock(&(philo->options->console_lock));
}

void print_death_message(t_philo *philo)
{
    pthread_mutex_lock(&(philo->options->console_lock));
    printf("%zu %d died\n", get_time_passed(philo), philo->id);
    pthread_mutex_unlock(&(philo->options->console_lock));
}