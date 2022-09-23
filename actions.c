/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:43:25 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/20 11:20:08 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_forks(t_philo *philo, uint64_t timestamp)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	ft_print_message(philo, FORK);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	ft_print_message(philo, FORK);
}

void	leave_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

void	eat(t_philo *philo, uint64_t timestamp)
{
	ft_print_message(philo, EATING);
	philo->eat_count++;
	philo->last_eat = timestamp;
	usleep(philo->data->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	ft_print_message(philo, SLEEPING);
	usleep(philo->data->time_to_sleep * 1000);
}

void	philo_thinking(t_philo *philo)
{
	ft_print_message(philo, THINKING);
}
