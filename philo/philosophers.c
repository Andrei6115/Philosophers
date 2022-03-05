/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:27:57 by calecia           #+#    #+#             */
/*   Updated: 2022/03/04 20:32:26 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*simulation_started(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	philo->last_eat = get_time();
	while (philo->count_live != 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (philo->count_live == INT32_MIN)
		{
			philo->count_live = 0;
		}
		philo->count_live--;
	}
	return (NULL);
}

void	start(t_philo *philo)
{
	int			i;
	pthread_t	spectator;

	i = 0;
	philo->state->itime.start_time = get_time();
	printf("%u %u %u %u %d\n", philo->state->itime.start_time, philo->state->itime.time_to_sleep, philo->state->itime.time_to_eat, philo->state->itime.time_to_die, philo->state->count_iter);
	while (i < philo->state->count_philo)
	{
		pthread_create(philo[i].thread, NULL, simulation_started, &philo[i]);
		usleep(25);
		i++;
	}
	pthread_create(&spectator, NULL, spect, philo);
	pthread_join(spectator, NULL);
}
