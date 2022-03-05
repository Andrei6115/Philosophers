/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:23:28 by calecia           #+#    #+#             */
/*   Updated: 2022/03/04 18:59:19 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

//typedef struct timeval	t_timeval;
// typedef struct s_time{
// 	struct timeval	start_time;
// 	struct timeval	time_to_die;
// 	struct timeval	time_to_eat;
// 	struct timeval	time_to_sleep;
// }	t_time;

typedef struct s_itime{
	unsigned int	start_time;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
}	t_itime;

typedef struct s_state
{
	int				count_philo;
	t_itime			itime;
	pthread_mutex_t	*message;
	int				cur_id;
	int				count_iter;
}	t_state;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_mutex_t	*fork_neighbor;
	int				alive;
	unsigned int	last_eat;
	int				id;
	t_state			*state;
	int				count_live;
	pthread_t		*thread;
}	t_philo;

void			start(t_philo *philo);

struct timeval	start_time(void);
void			time_print(struct timeval tv, int num_philo, char *str);
int				time_equal(struct timeval tv, struct timeval tv2);
//t_time			init_time(int argc, char **argv);
t_itime			init_itime(char **argv);
struct timeval	time_dist(struct timeval tv, struct timeval tv2);

int				ft_atoi(const char *str);

void			message(t_state *state, int id, char *msg);

void			take_fork(t_philo *philo);
void			put_fork(t_philo *philo);
int				philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

unsigned int	get_time(void);

void			ft_usleep(unsigned int ms);
unsigned int	get_time(void);

void			*spect(void *philo_v);
#endif