/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:16:17 by calecia           #+#    #+#             */
/*   Updated: 2022/02/26 19:49:09 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct timeval	start_time(void)
{
	struct timeval	tv;
	static int		have_time;

	if (have_time == 0)
	{
		gettimeofday(&tv, NULL);
		have_time = 1;
	}
	return (tv);
}

//if tv>t2 ret 1, tv==tv2 ret 0, tv<tv2 ret -1
int	time_equal(struct timeval tv, struct timeval tv2)
{
	if (tv.tv_sec > tv2.tv_sec)
	{
		return (1);
	}
	else if (tv.tv_sec < tv2.tv_sec)
	{
		return (-1);
	}
	else
	{
		if (tv.tv_usec > tv2.tv_usec)
		{
			return (1);
		}
		else if (tv.tv_usec < tv2.tv_usec)
		{
			return (-1);
		}
		else
		{
			return (0);
		}
	}
}

struct timeval	time_dist(struct timeval tv, struct timeval tv2)
{
	struct timeval	ret;

	if (tv2.tv_usec < 0)
	{
		ret.tv_usec = tv.tv_usec - tv2.tv_usec;
	//	printf("\n\t\t%d %d %d\n", ret.tv_usec, tv.tv_usec, tv2.tv_usec);
		ret.tv_sec = tv.tv_sec;
		ret.tv_sec += tv.tv_sec - tv2.tv_sec;
		if (ret.tv_usec >= 1000)
		{
			ret.tv_usec %= 1000;
			ret.tv_sec += 1;
		}
		return (ret);
	}
	ret.tv_usec = tv.tv_usec - tv2.tv_usec;
	ret.tv_sec = tv.tv_sec - tv2.tv_sec;
	if (ret.tv_usec < 0)
	{
		ret.tv_usec += 1000;
		ret.tv_sec -= 1;
	}
	return (ret);
}

void	time_print(struct timeval tv, int num_philo, char *str)
{
	int	usec;

	usec = tv.tv_usec;
	usec %= 1000;
	if (tv.tv_sec > 0)
		printf("%ld%03d %d %s\n", tv.tv_sec, usec, num_philo, str);
	else
		printf("%d %d %s\n", usec, num_philo, str);
}

// t_time	init_time(int argc, char **argv)
// {
// 	t_time	time;

// 	time.time_to_die.tv_usec = ft_atoi(argv[2]);
// 	time.time_to_die.tv_sec = time.start_time.tv_sec;
// 	time.time_to_eat.tv_usec = ft_atoi(argv[3]);
// 	time.time_to_eat.tv_sec = time.start_time.tv_sec;
// 	time.time_to_sleep.tv_usec = ft_atoi(argv[4]);
// 	time.time_to_sleep.tv_sec = time.start_time.tv_sec;
// 	return (time);
// }


