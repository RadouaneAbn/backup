#include "philo_bonus.h"

bool	check_philo_is_alive(t_philo *philo)
{
	bool	philo_status;

	// pthread_mutex_lock(&(philo->last_meal_lock));
	philo_status = get_current_time()
		- philo->last_meal <= (size_t)(philo->options->time2die);
	// pthread_mutex_unlock(&(philo->last_meal_lock));
	return (philo_status);
}

void reset_lastmeal(t_philo *philo, size_t time)
{
	// pthread_mutex_lock(&(philo->last_meal_lock));
	philo->last_meal = time;
	// pthread_mutex_unlock(&(philo->last_meal_lock));
}

void check_death(t_philo *philo)
{
	if (!check_philo_is_alive(philo))
	{
		printf("Philo %d is dead\n", philo->id);
		print_death_message(philo);
		exit(PHILO_DEAD);
	}
}

void eat(t_philo *philo)
{
	check_death(philo);
	sem_wait(philo->options->forks);
	print_message(philo, "has taken a fork");
	check_death(philo);
	sem_wait(philo->options->forks);
	print_message(philo, "has taken a fork");
	reset_lastmeal(philo, get_current_time());
	print_message(philo, "is eating");
	ft_usleep(philo->options->time2eat);
	sem_post(philo->options->forks);
	sem_post(philo->options->forks);
	philo->meals_count++;
	if (philo->meals_count >= philo->options->max_meals)
		exit(PHILO_FULL);
}

void dream(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->options->time2sleep);
	check_death(philo);
}

void *philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	// Wait for simulation start time
	printf("Philo %d is ready to start\n", philo->id);
	while (get_current_time() < philo->options->start_time)
	{
		usleep(100); // Small delay to avoid busy waiting
	}
	printf("Philo %d started\n", philo->id);
	
	// philo->last_meal = get_current_time();
	while (true)
	{
		printf("Philo %d is thinking\n", philo->id);
		eat(philo);
		dream(philo);
		print_message(philo, "is thinking");
		check_death(philo);
	}
	return NULL;
}

void wait_for_children(t_table *table)
{
    int status;
    int finished_philos = 0;
    
    while (finished_philos < table->options.total_philos)
    {
        waitpid(-1, &status, 0);
        finished_philos++;
        
        if (WEXITSTATUS(status) == PHILO_DEAD)
        {
            // A philosopher died, kill all remaining processes
            int i = 0;
            while (i < table->options.total_philos)
            {
                kill(table->philos[i].pid, SIGKILL);
                i++;
            }
            break;
        }
    }
}

bool create_philos(t_table *table)
{
    int i;

    i = 0;

    while (i < table->options.total_philos)
    {
        // Initialize philosopher data
        table->philos[i].id = i + 1;
        table->philos[i].options = &(table->options);
        table->philos[i].meals_count = 0;
        table->philos[i].last_meal = get_current_time();
        
        // // Initialize mutex for last meal protection
        // if (pthread_mutex_init(&(table->philos[i].last_meal_lock), NULL) != 0)
        // {
        //     perror("pthread_mutex_init (last_meal_lock)");
        //     exit(1);
        // }
		printf("Philo %d is created\n", table->philos[i].id);
        
        table->philos[i].pid = fork();
        if (table->philos[i].pid == -1)
        {
            perror("fork");
            return (false);
        }
        if (table->philos[i].pid == 0)
        {
            // Child process: start philosopher routine
            philo_routine(&(table->philos[i]));
        }
        i++;
    }

    return (true);
}

int main(int ac, char **av)
{
	t_table table;
	bool status;

	if (ac > 6 || ac < 5)
	{
		printf(USAGE_ERROR_MSG, av[0]);
		return (1);
	}
	ft_bzero(&table, sizeof(t_table));
	printf("Convert arguments...\n");
	status = convert_arguments(&table, ac, av);
	if (status == false)
		return (1);
	if (table.options.total_philos == 0 || table.options.max_meals == 0)
		return (0);
	printf("Initialize simulation...\n");
	if (status == true)
		status = init_simulation(&table);
	printf("create_philos...\n");
	if (status == true)
		status = create_philos(&table);
	if (status == true)
		wait_for_children(&table);
	remove_sems(&table);
	if (status == false)
		return (1);
	return (0);
}