#include "philo.h"

bool sim_is_running(t_philo *philo)
{
    bool sim_status;

    pthread_mutex_lock(&(philo->options->sim_lock));
    sim_status = philo->options->sim_running;
    pthread_mutex_unlock(&(philo->options->sim_lock));
    return (sim_status);
}

void start_sim(t_table *table)
{
    pthread_mutex_lock(&(table->options.sim_lock));
    table->options.sim_running = true;
    pthread_mutex_unlock(&(table->options.sim_lock));
}

void stop_sim(t_table *table)
{
    pthread_mutex_lock(&(table->options.sim_lock));
    table->options.sim_running = false;
    pthread_mutex_unlock(&(table->options.sim_lock));
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void ft_usleep(size_t time)
{
    size_t start;

    start = get_current_time();
    while (get_current_time() - start < time)
        usleep(100);
}

void ft_usleep_safe(t_philo *philo, size_t time)
{
    size_t start;

    start = get_current_time();
    while (get_current_time() - start < time && sim_is_running(philo))
        usleep(100);
}

void set_lastmeal(t_philo *philo, size_t time)
{
	pthread_mutex_lock(&(philo->last_meal_lock));
	philo->last_meal = time;
	pthread_mutex_unlock(&(philo->last_meal_lock));
}

bool philo_is_alive(t_philo *philo)
{
    bool philo_status;

    pthread_mutex_lock(&(philo->last_meal_lock));
    philo_status = get_current_time() - philo->last_meal <= (size_t)(philo->options->time2die);
    pthread_mutex_unlock(&(philo->last_meal_lock));
    // printf("%d => %d\n", philo->id, (int)philo_status);
    return (philo_status);
}

bool philo_has_eaten_max_meals(t_philo *philo)
{
    bool max_meals_status;

    pthread_mutex_lock(&(philo->max_meals_lock));
    max_meals_status = philo->meals_count >= philo->options->max_meals;
    pthread_mutex_unlock(&(philo->max_meals_lock));
    return (max_meals_status);
}

