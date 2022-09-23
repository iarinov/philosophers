/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:45:58 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/16 16:21:58 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init(int argc, char **argv, t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->is_running = true;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
}

void	init_mutexes(t_data *data)
{
	int	index;

	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	index = -1;
	while (++index < data->number_of_philosophers)
		pthread_mutex_init(&data->forks[index], NULL);
	pthread_mutex_init(&data->write, NULL);
}

void	init_philos(t_data *data)
{
	int	index;

	index = -1;
	while (++index < data->number_of_philosophers)
	{
		data->philo[index].id = index + 1;
		data->philo[index].l_fork = index;
		data->philo[index].r_fork = (index + 1) % data->number_of_philosophers;
		data->philo[index].thread_id = 0;
		data->philo[index].data = data;
		data->philo[index].last_eat = 0;
		data->philo[index].eat_count = 0;
		data->philo[index].done = false;
	}
}

void	init_threads(t_data *data)
{
	int			index;
	pthread_t	id;

	index = -1;
	while (++index < data->number_of_philosophers)
	{
		pthread_create(&data->philo[index].thread_id, NULL,
			&life_cycle, &data->philo[index]);
	}
	pthread_create(&id, NULL, &life_cycle_checker, data);
	pthread_join(id, NULL);
}
