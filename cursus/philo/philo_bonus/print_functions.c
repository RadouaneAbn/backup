#include "philo_bonus.h"

size_t get_time_passed(t_philo *philo)
{
	return (get_current_time() - philo->options->start_time);
}

void print_message(t_philo *philo, char *msg)
{
    sem_wait(philo->options->console_sem);
    if (sim_is_running(philo) == true)
        printf("%zu %d %s\n", get_time_passed(philo), philo->id, msg);
    sem_post(philo->options->console_sem);
}

void print_death_message(t_philo *philo)
{
    sem_wait(philo->options->console_sem);
    printf("%zu %d died\n", get_time_passed(philo), philo->id);
    // sem_post(philo->options->console_sem);
}