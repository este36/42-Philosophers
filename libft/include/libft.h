/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 22:54:43 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MIN_DSTR_CAP 256
# define MIN_DARR_CAP 256

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_dstr
{
	char	*buf;
	size_t	len;
	size_t	cap;
}	t_dstr;

typedef struct s_str_ref
{
	char	*buf;
	size_t	len;
}	t_str_ref;

t_str_ref	c_str_ref(const char *s);
int			str_ref_cmp(t_str_ref *s1, t_str_ref *s2);

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

int			ft_dstr_init(t_dstr *s, size_t cap);
int			ft_dstrputc(t_dstr *dst, char c);
int			ft_dstrncat(t_dstr *dst, char *src, size_t n);
int			ft_dstrcat(t_dstr *dst, char *src);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strchr_fn(const char *s, int (*fn)(int c));
char		*ft_strrchr(const char *s, int c);
char		*ft_strrchr_fn(const char *s, int (*fn)(int c));
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
double		ft_atod(const char *nptr);
long		ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t prev_size, size_t size);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, const size_t s_len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_fn(char const *s1, char const *s2, int (*fn)(int c));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrim_fn(char const *s1, int (*fn)(int c));
char		**ft_split(char const *s, char c);
void		str_arr_free(char **strs);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstget(t_list *lst, size_t index);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstlast_back(t_list **lst, t_list *new);
t_list		*ft_lstpop_front(t_list **lst);
t_list		*ft_lstpop_back(t_list **lst);
void		ft_lstrot_front(t_list **lst);
void		ft_lstrot_back(t_list **lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif // LIBFT_H
