/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:42:27 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/16 16:17:31 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print_message(t_philo *philo, int index)
{
	unsigned int	time;

	if (!philo)
		return ;
	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start;
	if (index == FORK)
		ft_printf("%u\t%d has taken a fork\n", time, philo->id);
	else if (index == EATING)
		ft_printf("%u\t%d is eating\n", time, philo->id);
	else if (index == SLEEPING)
		ft_printf("%u\t%d is sleeping\n", time, philo->id);
	else if (index == THINKING)
		ft_printf("%u\t%d is thinking\n", time, philo->id);
	else if (index == DIED)
		ft_printf("%u\t%d died\n", time, philo->id);
	else if (index == DONE)
		ft_printf("Simulation is Done :)\n");
	if (index != DIED && index != DONE)
		pthread_mutex_unlock(&philo->data->write);
}
