NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

LIBFT = libft/libft.a

INCLUDES = -Iincludes -I$$HOME/.local/include -Ilibft/includes

SRCS_DIR = src

SRCS =\
$(SRCS_DIR)/main.c\

OBJS_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) bonus -C libft

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS_DIR)	

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

update_libft:
	rm -rf libft
	git clone git@github.com:este36/libft.git
	rm -rf libft/.git

norm:
	@norminette | grep Error || true


.PHONY: clean fclean all re update_libft norm
