/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spect.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:01:04 by calecia           #+#    #+#             */
/*   Updated: 2022/03/05 16:43:17 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->state->count_philo)
	{
		if (philo[i].count_live != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	philo_dead(t_philo *philo)
{
	unsigned int	time;

	time = get_time();
	if (philo->last_eat + philo->state->itime.time_to_die < time)
	{
		philo->alive = 0;
		return (1);
	}
	return (0);
}

void	*spect(void *philo_v)
{
	t_philo			*philo;
	int				i;
	unsigned int	tv;

	philo = (t_philo *)philo_v;
	i = 0;
	while (philo[i].alive && !all_eat(philo))
	{
		if (philo_dead(&philo[i]))
			break ;
		usleep(10);
		i++;
		if (philo->state->count_philo == i)
			i = 0;
	}
	pthread_mutex_lock(philo->state->message);
	if (!philo[i].alive)
	{
		tv = get_time();
		printf("%u %d %s\n", tv - philo->state->itime.start_time, i, "is dead");
	}
	else
		printf ("all alive\n");
	return (NULL);
}
