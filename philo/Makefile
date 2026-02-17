NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =\
main.c\
ft_atol.c\
utils.c\
sleep_ms.c\
log.c\
prop_utils.c\
monitor_utils.c\
monitor_mutexes.c\
monitor_routine.c\
philosopher_routine.c\
run_simulation.c\

OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: ./%.c
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

norm:
	norminette | grep -v 'OK!' || true

.PHONY: clean fclean all re
