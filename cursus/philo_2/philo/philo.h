#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/* Error messages */
# define USAGE_ERROR_MSG "Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
// # define PHILO_N_ERROR_MSG "Number of philosophers must be between 0-200\n"
// # define TIME_TO_DIE_ERROR_MSG "Time to die must be greater than 0\n"
// # define TIME_TO_EAT_ERROR_MSG "Time to eat must be greater than 0\n"
// # define TIME_TO_SLEEP_ERROR_MSG "Time to sleep must be greater than 0\n"
// # define MAX_MEALS_ERROR_MSG "Max meals that a philo must eat must be great or equal to 0\n"

typedef enum e_status
{
    RUNNING,
    MAX_MEALS,
    PHILO_DEAD
} t_status;

/* Philo strcuts */
typedef struct s_options
{
    size_t start_time;
    int total_philos;
    int total_forks;
    int time2die;
    int time2eat;
    int time2sleep;
    int max_meals;
    bool sim_running;
    pthread_mutex_t console_lock;
    pthread_mutex_t sim_lock;
} t_options;

// typedef struct s_fork
// {
//     int id;
//     bool available;
//     pthread_mutex_t lock;
// } t_fork;

typedef struct s_philo
{
    int id;
    pthread_t thread_id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_options *options;
    int meals_count;
    pthread_mutex_t last_meal_lock;
    pthread_mutex_t max_meals_lock;
    size_t last_meal;
} t_philo;

typedef struct s_table
{
    pthread_t monitor_pthread_id;
    t_philo philos[200];
    pthread_mutex_t forks[200];
    t_options options;
} t_table;

typedef bool t_checker(t_table *);

bool     ft_atoi(const char *str, int *result);
bool convert_arguments(t_table *table, int ac , char **av);
void *ft_bzero(void *data, size_t size);
int init_simulation(t_table *table);
void *routine(void *args);
void *monitor(void *args);

/* Utils */
void set_lastmeal(t_philo *philo, size_t time);
bool sim_is_running(t_philo *philo);
size_t	get_current_time(void);
void ft_usleep(size_t time);
bool philo_is_alive(t_philo *philo);
void start_sim(t_table *table);
void stop_sim(t_table *table);
bool philo_has_eaten_max_meals(t_philo *philo);
void ft_usleep_safe(t_philo *philo, size_t time);
void print_message(t_philo *philo, char *msg);
void print_death_message(t_philo *philo);

/* Debug */
void print_table(t_table *table);

#endif