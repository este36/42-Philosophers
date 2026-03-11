/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:27:53 by emercier          #+#    #+#             */
/*   Updated: 2026/03/11 14:12:50 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>

typedef void	*(*t_pthread_cb)(void *);

long			ft_atol(const char *nptr);
int				ft_isspace(int c);
int				ft_isdigit(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t prev_size, size_t size);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
long			now_ms(void);
void			sleep_ms(int ms);

typedef struct s_prop
{
	pthread_mutex_t	mtx;
	long			val;
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
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_philo_params;

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				id;
	t_philo_params	params;
	long			start_ms;
	t_prop			state;
	t_prop			can_eat;
	t_prop			meal_count;
	t_prop			last_meal;
	t_prop			*should_stop;
	t_prop			*can_start;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*cout;
}	t_philosopher;

typedef struct s_monitor
{
	t_philosopher	*philos;
	t_philosopher	**choices;
	size_t			choices_count;
	t_prop			can_start;
	t_prop			should_stop;
	pthread_mutex_t	cout;
	t_philo_params	params;
	long			start_ms;
}	t_monitor;

typedef bool	(*t_monitor_loop)(t_monitor *m);

long			get_prop(t_prop *prop);
long			set_prop(t_prop *prop, long val);
void			wait_prop(t_prop *should_stop, t_prop *prop, long val);
void			increment_prop(t_prop *prop);

t_philosopher	*get_left_philo(t_monitor *m, size_t philo_index);
t_philosopher	*get_right_philo(t_monitor *m, size_t philo_index);
bool			philo_can_eat(t_monitor *m, t_philosopher *p);

bool			monitor_choose(t_monitor *m);
void			monitor_destroy_mutexes(t_monitor *m, size_t philos_count);
bool			monitor_create_mutexes(t_monitor *m);
bool			monitor_init(t_monitor *m, t_philo_params params);
void			monitor_destroy(t_monitor *m);
bool			monitor_philo_eat(t_monitor *m, t_philosopher *p);

# define LOG_FORK_TAKEN	"has taken a fork"
# define LOG_EATING		"is eating"
# define LOG_SLEEPING	"is sleeping"
# define LOG_THINKING	"is thinking"
# define LOG_DIED		"died"

void			philo_log(t_philosopher *philo, const char *msg);
void			philo_spend_time(t_philosopher *p, long ms);
bool			philo_is_dead(t_philosopher *p);

bool			run_simulation(t_monitor *m);
void			*monitor_routine(t_monitor *m);
void			*philosopher_routine(t_philosopher *p);

#endif
