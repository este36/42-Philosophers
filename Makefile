
all: mandatory bonus

mandatory:
	@$(MAKE) -C philo

bonus:
	@$(MAKE) -C philo_bonus

update_libft:
	rm -rf libft
	git clone git@github.com:este36/libft.git
	rm -rf libft/.git

fclean:
	@$(MAKE) fclean -C philo_bonus
	@$(MAKE) fclean -C philo

re:
	@$(MAKE) re -C philo_bonus
	@$(MAKE) re -C philo

norm:
	@norminette | grep Error || true

.PHONY: all mandatory bonus update_libft norm
