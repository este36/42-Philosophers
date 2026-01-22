/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:27:53 by emercier          #+#    #+#             */
/*   Updated: 2026/01/22 16:39:59 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# define MIN_DARR_CAP 16

typedef struct s_darr
{
	void	*arr;
	size_t	len;
	size_t	cap;
	size_t	el_size;
}	t_darr;

int			ft_darr_init(t_darr *a, size_t cap, size_t el_size);
int			ft_darr_push(t_darr *a, void *el);
void		*ft_darr_get(t_darr *a, size_t index);

void		ft_bzero(void *s, size_t n);
int			ft_isspace(int c);
int			ft_isdigit(int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t prev_size, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);

typedef struct s_prop
{
	pthread_mutex_t	mtx;
	int				val;
}	t_prop;

enum e_philo_state
{
	STATE_UNSET,
	STATE_ASKING,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DEAD,
	STATE_MAX,
};

typedef struct s_philo_params
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_philo_params;

typedef struct s_philosopher
{
	pthread_t		tid;
	int				id;
	t_philo_params	params;
	struct timeval	start;
	t_prop			state;
	t_prop			can_eat;
	t_prop			eat_times;
	t_prop			last_meal;
	t_prop			*stop;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*cout;
}	t_philosopher;

typedef struct s_monitor
{
	t_darr			philos; /* t_darr<t_philosopher> */
	t_prop			stop;
	pthread_mutex_t	*cout;
	t_philo_params	params;
	struct timeval	start;
	size_t			deaths;
}	s_monitor;

int		get_prop(t_prop *prop);
int		set_prop(t_prop *prop, int val);

# define LOG_FORK_TAKEN "has taken a fork"
# define LOG_EATING "is eating"
# define LOG_SLEEPING "is sleeping"
# define LOG_THINKING "is thinking"
# define LOG_DIED "died"

void	log_taken_a_fork(t_philosopher *philo);
void	log_eating(t_philosopher *philo);
void	log_sleeping(t_philosopher *philo);
void	log_thinking(t_philosopher *philo);
void	log_died(t_philosopher *philo);

void	monitor(t_monitor *him);
void	philosopher(t_philosopher *him);

#endif
