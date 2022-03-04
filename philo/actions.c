/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:48:22 by calecia           #+#    #+#             */
/*   Updated: 2022/03/03 19:28:12 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(philo->fork_neighbor);
	message(philo->state, philo->id, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(philo->fork_neighbor);
}

//if philo dead return 0, else 1
int	philo_eat(t_philo *philo)
{
	unsigned int	time;
	
	if (time - philo->last_eat > philo->state->itime.time_to_die)
	{
		philo->alive = 0;
		return (0);
	}
	take_fork(philo);
	philo->last_eat = time;
	message(philo->state, philo->id, "is eating");
	ft_usleep(philo->state->itime.time_to_eat);
	put_fork(philo);
	return (1);
}

void	philo_sleep(t_philo *philo)
{
	message(philo->state, philo->id, "is sleeping");
	ft_usleep(philo->state->itime.time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	message(philo->state, philo->id, "is thinking");
}
