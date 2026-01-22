/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:27:53 by emercier          #+#    #+#             */
/*   Updated: 2026/01/21 21:05:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# define MIN_DARR_CAP 256

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

typedef struct s_philo
{
}	t_philo;

#endif
