
all: mandatory bonus

mandatory:
	$(MAKE) re -C philo

bonus:
	$(MAKE) re -C philo_bonus

update_libft:
	rm -rf libft
	git clone git@github.com:este36/libft.git
	rm -rf libft/.git

norm:
	@norminette | grep Error || true

.PHONY: all mandatory bonus update_libft norm
