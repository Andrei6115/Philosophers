/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spect.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:01:04 by calecia           #+#    #+#             */
/*   Updated: 2022/03/03 18:52:58 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->state->count_philo)
	{
		if (philo[i].count_live != 0)
			return (0);
		i++;
	}
	return (1);
}

void	*spect(void *philo_v)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philo_v;
	i = 0;
	while (philo[i].alive && !all_eat(philo))
	{
		usleep(10);
		i++;
		if (philo->state->count_philo == i)
			i = 0;
	}
	message(philo->state, i, "is dead");
	return (NULL);
}
