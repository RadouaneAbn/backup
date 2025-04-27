#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

/**
 * Input example:
 *  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
*/

/**
 * Philosopher struct
*/

# define USAGE_ERROR_MSG "Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define PHILO_N_ERROR_MSG "Number of philosophers must be greater than 0\n"
# define TIME_TO_DIE_ERROR_MSG "Time to die must be greater than 0\n"
# define TIME_TO_EAT_ERROR_MSG "Time to eat must be greater than 0\n"
# define TIME_TO_SLEEP_ERROR_MSG "Time to sleep must be greater than 0\n"

typedef char t_bool;

typedef enum e_state
{
    EATING,
    SLEEPING,
    THINKING,
    DEAD
} t_state;

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
    pthread_t   philo;
    int         id;
    int         last_meal;
    t_state     state;
    t_table     *table;
}               t_philo;

/**
 * Table struct
*/

typedef struct s_table
{
    t_philo *philos;
    pthread_mutex_t *forks;
    t_bool philo_died;
    int number_of_philosophers;
    int number_of_forks;
    int time_to_sleep;
    int time_to_die;
    int time_to_eat;
    int must_eat_meals_count;
    int simulation_running;
} t_table;

// typedef struct s_thread_args
// {
//     int philo_id;
//     t_table *table;
// } t_thread_args;

/* Helper functions */
int     ft_atoi(const char *str);
void ft_usleep(int time, t_philo *philo);

#endif