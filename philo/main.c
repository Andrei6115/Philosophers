/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:15:33 by calecia           #+#    #+#             */
/*   Updated: 2022/03/03 17:23:28 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// unsigned int	get_time(void)
// {
// 	struct timeval	current_time;

// 	gettimeofday(&current_time, NULL);
// 	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
// }

t_philo	philo_init(int id, t_state *state)
{
	t_philo	philo;

	philo.alive = 1;
	philo.id = id;
	philo.state = state;
	philo.last_eat = 0;
	philo.count_live = state->count_iter;
	philo.thread = malloc(sizeof(pthread_t));
	pthread_mutex_init(&(philo.fork), NULL);
	return (philo);
}

void	message(t_state *state, int id, char *msg)
{
	unsigned int	tv;

	pthread_mutex_lock(state->message);
	tv = get_time();
	printf("%u %d %s\n", tv - state->itime.start_time, id, msg);
	pthread_mutex_unlock(state->message);
}

void	init_forks_neighbors(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->state->count_philo)
	{
		printf("\t%d\t%d\n", i, (i + 1) % (philo->state->count_philo));
		philo[i].fork_neighbor
			= &philo[(i + 1) % (philo->state->count_philo)].fork;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_itime		time;
	t_philo		*philo;
	int			i;
	int			count;
	t_state		state;

	count = ft_atoi(argv[1]);
	printf("%p\n", philo);
	state.count_iter = INT32_MAX;
	if (argc != 5)
	{
		if (argc == 6)
		{
			state.count_iter = ft_atoi(argv[5]);
		}
		else
			exit (2);
	}
	time.start_time = get_time();
	time = init_itime(argc, argv);
	if (time.time_to_sleep <= 0 || time.time_to_die <= 0
		|| time.time_to_eat <= 0 || state.count_iter <= 0)
	{
		printf("Error\n");
		return (404);
	}
	printf("%u\n%u\n%u\n%u\n%u\n", time.start_time, time.start_time, time.time_to_die,
		time.time_to_eat, time.time_to_sleep);
	state.count_philo = count;
	state.message = malloc(sizeof(pthread_mutex_t));
	state.itime = time;
	pthread_mutex_init(state.message, NULL);
	philo = malloc(sizeof(t_philo) * count);
	i = 0;
	while (i < count)
	{
		philo[i] = philo_init(i, &state);
		i++;
	}
	init_forks_neighbors(philo);
	start(philo);
	pthread_mutex_destroy(state.message);
	return (0);
}
