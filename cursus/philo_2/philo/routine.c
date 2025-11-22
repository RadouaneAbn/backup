#include "philo.h"

void increment_meal_cout(t_philo *philo)
{
    pthread_mutex_lock(&(philo->max_meals_lock));
    philo->meals_count++;
    pthread_mutex_unlock(&(philo->max_meals_lock));
}

void shufle_forks(t_philo *philo, pthread_mutex_t **lf, pthread_mutex_t **rf)
{
	if (philo->id % 2 == 1)
	{
		*lf = philo->left_fork;
		*rf = philo->right_fork;
	}
	else
	{
		*lf = philo->right_fork;
		*rf = philo->left_fork;
	}
}

void start_eating(t_philo *philo)
{
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	set_lastmeal(philo, get_current_time());
	ft_usleep_safe(philo, philo->options->time2eat);
	increment_meal_cout(philo);
}

void start_routine(t_philo *philo)
{
	pthread_mutex_t *lf;
	pthread_mutex_t *rf;

	shufle_forks(philo, &lf, &rf);
	set_lastmeal(philo, get_current_time());
	while (sim_is_running(philo) == true)
	{
		// if (philo->id % 2)
		// 	usleep(500);
		print_message(philo, "is thinking");
		pthread_mutex_lock(lf);
		if (sim_is_running(philo) == true)
		{
			print_message(philo, "has taken a fork");
			pthread_mutex_lock(rf);
			if (sim_is_running(philo) == true)
			{
				start_eating(philo);
			}
			pthread_mutex_unlock(rf);
		}
		pthread_mutex_unlock(lf);
		if (sim_is_running(philo) == true)
		{
			print_message(philo, "is sleeping");
			ft_usleep_safe(philo, philo->options->time2sleep);
		}
	}
}

void run_one_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	set_lastmeal(philo, get_current_time());
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	ft_usleep_safe(philo, philo->options->time2die);
	pthread_mutex_unlock(philo->left_fork);
}

void *routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *) args;
	if(philo->options->total_philos == 1)
		return(run_one_philo(philo), args);
	start_routine(philo);
	return (args);
}
