/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:17:46 by aiarinov          #+#    #+#             */
/*   Updated: 2022/09/16 16:17:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf.h"

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DONE 6

typedef struct s_data	t_data;

typedef struct philo
{
	int			id;
	int			l_fork;
	int			r_fork;
	int			eat_count;
	int			last_eat;
	pthread_t	thread_id;
	t_data		*data;
	bool		done;
}	t_philo;

typedef struct s_data
{
	int				time_to_sleep;
	int				time_to_eat;
	int				number_of_philosophers;
	int				time_to_die;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	int				count_done;
	bool			is_running;
	pthread_mutex_t	*death;
	pthread_mutex_t	*stop;
	unsigned int	start;
	t_philo			*philo;
}	t_data;

void			take_forks(t_philo *philo, uint64_t timestamp);
void			leave_fork(t_philo *philo);
void			eat(t_philo *philo, uint64_t timestamp);
void			philo_sleep(t_philo *philo);
void			philo_thinking(t_philo *philo);
void			destroy(t_data *data);
void			ft_usleep(unsigned int time_in_ms);
unsigned int	get_time(void);
void			init(int argc, char **argv, t_data *data);
void			init_mutexes(t_data *data);
void			init_threads(t_data *data);
void			init_philos(t_data *data);
void			*life_cycle_checker(void *arg);
void			*life_cycle(void *arg);
void			ft_print_message(t_philo *philo, int index);

#endif
