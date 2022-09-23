/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:59:18 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/19 14:11:25 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	parcing(int argc, char **argv)
{
	int	i;

	i = 1;
	if ((argc != 5 && argc != 6))
		return (1);
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || argv[i][0] == '-')
			return (1);
		if (ft_atoi(argv[i]) == -1 || ft_atoi(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	die(t_data *data, uint64_t timestamp, int index)
{
	pthread_mutex_lock(&data->write);
	ft_printf("%u\t%d philo has died\n", timestamp
		- data->start, index + 1);
	pthread_mutex_unlock(&data->write);
	data->is_running = false;
}

void	*life_cycle_checker(void *arg)
{
	int			index;
	uint64_t	timestamp;
	t_data		*data;
	t_philo		*philo;

	data = (t_data *)arg;
	index = 0;
	while (1)
	{
		if (data->count_done == data->number_of_philosophers)
			break ;
		if (index == data->number_of_philosophers)
			index = 0;
		usleep(1000);
		timestamp = get_time();
		if (!data->philo[index].done
			&& (int)(timestamp - data->philo[index].last_eat)
			> data->time_to_die)
		{
			die(data, timestamp, index);
			break ;
		}
		index++;
	}
	return (NULL);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if (philo->id % 2 == 0)
	{
		philo_thinking(philo);
		usleep(philo->data->time_to_eat * 0.25 * 1000);
	} 
	while (philo->data->is_running)
	{
		take_forks(philo, get_time());
		eat(philo, get_time());
		leave_fork(philo);
		philo_thinking(philo);
		if (philo->eat_count == philo->data->must_eat)
		{
			philo->done = true;
			philo->data->count_done++;
			break ;
		}
		philo_sleep (philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parcing(argc, argv) == 1)
	{
		write(2, "error\n", 6);
		return (1);
	}
	init(argc, argv, &data);
	data.start = get_time();
	init_mutexes(&data);
	init_philos(&data);
	init_threads(&data);
	destroy(&data);
	return (0);
}
