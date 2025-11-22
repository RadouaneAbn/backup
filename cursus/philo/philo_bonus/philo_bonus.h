#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>

# define RESET "\033[0m"
# define BRED "\033[1;31m"
# define BACKGROUND_RED "\e[41m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define UPURPLE "\e[4;35m"

# define FORK_SEM_NAME "/forks_sem"
# define CONSOLE_SEM_NAME "/console_sem"
# define SIM_READY_SEM_NAME "/sim_ready_sem"
# define PHILO_FULL 42
# define PHILO_DEAD 32

/* Error messages */
# define USAGE_ERROR_MSG "Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

/* Philo strcuts */
typedef struct s_options
{
    sem_t *forks;
    sem_t *console_sem;
    size_t start_time;
    int total_philos;
    int total_forks;
    int time2die;
    int time2eat;
    int time2sleep;
    int max_meals;
    bool sim_running;
} t_options;

typedef struct s_philo
{
    int id;
    pid_t pid;
    t_options *options;
    int meals_count;
    pthread_mutex_t last_meal_lock;
    pthread_mutex_t max_meals_lock;
    pthread_t monitor_pthread_id;
    size_t last_meal;
} t_philo;

typedef struct s_table
{
    t_philo philos[200];
    sem_t *forks;
    t_options options;
} t_table;

typedef bool t_checker(t_table *);

bool     ft_atoi(const char *str, int *result);
bool convert_arguments(t_table *table, int ac , char **av);
void *ft_bzero(void *data, size_t size);
int init_simulation(t_table *table);
bool sim_is_running(t_philo *philo);
void remove_sems(t_table *table);
size_t	get_current_time(void);
void ft_usleep(size_t time);

size_t get_time_passed(t_philo *philo);
void print_message(t_philo *philo, char *msg);
void print_death_message(t_philo *philo);

void remove_sems(t_table *table);
bool create_sems(t_table *table);
int init_simulation(t_table *table);


/* Debug */
void print_table(t_table *table);

#endif