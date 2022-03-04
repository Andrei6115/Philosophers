/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:25:47 by calecia           #+#    #+#             */
/*   Updated: 2022/03/02 22:16:47 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(unsigned int ms)
{
	long	time;

	time = get_time();
	usleep(ms * 920);
	while (get_time() < time + (long)ms)
		usleep(ms * 3);
}

t_itime	init_itime(int argc, char **argv)
{
	t_itime	time;

	time.time_to_die = ft_atoi(argv[2]);
	time.time_to_eat = ft_atoi(argv[3]);
	time.time_to_sleep = ft_atoi(argv[4]);
	return (time);
}
