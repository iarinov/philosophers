/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:20:25 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/16 16:15:03 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
