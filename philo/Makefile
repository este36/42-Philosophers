NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

SRCS_DIR = .

SRCS =\
$(SRCS_DIR)/main.c\
$(SRCS_DIR)/ft_atol.c\
$(SRCS_DIR)/ft_darr.c\
$(SRCS_DIR)/utils.c\
$(SRCS_DIR)/log.c\

OBJS_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean fclean all re
