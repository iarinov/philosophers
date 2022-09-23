/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:37:58 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/12 12:39:44 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_threads(t_data *data)
{
	int	index;

	index = -1;
	while (++index < data->number_of_philosophers)
		pthread_detach(data->philo[index].thread_id);
}

void	destroy(t_data *data)
{
	int	index;

	destroy_threads(data);
	index = -1;
	while (++index < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[index]);
	pthread_mutex_destroy(&data->write);
	free(data->philo);
	free(data->forks);
}
