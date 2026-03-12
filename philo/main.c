/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:23:09 by emercier          #+#    #+#             */
/*   Updated: 2026/03/12 18:32:32 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_args(t_philo_params *params, int argc, char **argv)
{
	memset(params, 0, sizeof(*params));
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: unvalid number of arguments\n", 35);
		return (false);
	}
	params->number_of_philosophers = (int)ft_atol(argv[1]);
	params->time_to_die = (int)ft_atol(argv[2]);
	params->time_to_eat = (int)ft_atol(argv[3]);
	params->time_to_sleep = (int)ft_atol(argv[4]);
	if (argc == 6)
		params->times_must_eat = (int)ft_atol(argv[5]);
	if (params->number_of_philosophers <= 0 || params->time_to_die <= 0
		|| params->time_to_eat <= 0 || params->time_to_sleep <= 0
		|| (argc == 6 && params->times_must_eat <= 0))
	{
		write(2, "Error: arguments should be greater than zero\n", 45);
		return (false);
	}
	return (true);
}

void	print_usage(char *program_name)
{
	printf("Usage: %s number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
		program_name);
}

int	main(int argc, char **argv)
{
	t_philo_params		params;
	t_monitor			monitor;

	if (!parse_args(&params, argc, argv))
	{
		print_usage(argv[0]);
		return (1);
	}
	if (!monitor_init(&monitor, params))
		return (1);
	if (!run_simulation(&monitor))
	{
		monitor_destroy(&monitor);
		return (1);
	}
	log_debug("END: %d\n", now_ms() - monitor.start_ms);
	monitor_destroy(&monitor);
	return (0);
}
