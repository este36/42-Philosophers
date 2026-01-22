
all: mandatory bonus

mandatory:
	@$(MAKE) --no-print-directory re -C philo

bonus:
	@$(MAKE) --no-print-directory re -C philo_bonus

update_libft:
	rm -rf libft
	git clone git@github.com:este36/libft.git
	rm -rf libft/.git

norm:
	@norminette | grep Error || true

.PHONY: all mandatory bonus update_libft norm
