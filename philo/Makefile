
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =\
main.c\
ft_atol.c\
utils.c\
log.c\
prop_utils.c\
monitor_utils.c\
monitor_choose.c\
monitor_mutexes.c\
monitor_routine.c\
philosopher_routine.c\
philo_sleep.c\
philo_utils.c\
sleep_ms.c\
run_simulation.c\
#log_debug.c\

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

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --fair-sched=yes ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

.PHONY: clean fclean all re
