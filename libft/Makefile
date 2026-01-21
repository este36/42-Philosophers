NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = Libft
LIBFT_SRCS =\
$(LIBFT_DIR)/ft_isalpha.c\
$(LIBFT_DIR)/ft_isspace.c\
$(LIBFT_DIR)/ft_memcpy.c\
$(LIBFT_DIR)/ft_strrchr.c\
$(LIBFT_DIR)/ft_strrchr_fn.c\
$(LIBFT_DIR)/ft_isdigit.c\
$(LIBFT_DIR)/ft_memmove.c\
$(LIBFT_DIR)/ft_strncmp.c\
$(LIBFT_DIR)/ft_isalnum.c\
$(LIBFT_DIR)/ft_strlcpy.c\
$(LIBFT_DIR)/ft_strlen.c\
$(LIBFT_DIR)/ft_strlcat.c\
$(LIBFT_DIR)/ft_memchr.c\
$(LIBFT_DIR)/ft_isascii.c\
$(LIBFT_DIR)/ft_isprint.c\
$(LIBFT_DIR)/ft_toupper.c\
$(LIBFT_DIR)/ft_memcmp.c\
$(LIBFT_DIR)/ft_memset.c\
$(LIBFT_DIR)/ft_tolower.c\
$(LIBFT_DIR)/ft_strnstr.c\
$(LIBFT_DIR)/ft_bzero.c\
$(LIBFT_DIR)/ft_strchr.c\
$(LIBFT_DIR)/ft_strchr_fn.c\
$(LIBFT_DIR)/ft_atoi.c\
$(LIBFT_DIR)/ft_atod.c\
$(LIBFT_DIR)/ft_atol.c\
$(LIBFT_DIR)/ft_calloc.c\
$(LIBFT_DIR)/ft_realloc.c\
$(LIBFT_DIR)/ft_strdup.c\
$(LIBFT_DIR)/ft_strndup.c\
$(LIBFT_DIR)/ft_substr.c\
$(LIBFT_DIR)/ft_strjoin.c\
$(LIBFT_DIR)/ft_strtrim.c\
$(LIBFT_DIR)/ft_strtrim_fn.c\
$(LIBFT_DIR)/ft_split.c\
$(LIBFT_DIR)/ft_split_fn.c\
$(LIBFT_DIR)/ft_itoa.c\
$(LIBFT_DIR)/ft_utoa.c\
$(LIBFT_DIR)/ft_dstr.c\
$(LIBFT_DIR)/ft_darr.c\
$(LIBFT_DIR)/ft_hmap.c\
$(LIBFT_DIR)/ft_hmap_insert.c\
$(LIBFT_DIR)/ft_hmap_delete.c\
$(LIBFT_DIR)/ft_hmap_resize.c\
$(LIBFT_DIR)/ft_hmap_get.c\
$(LIBFT_DIR)/ft_str_ref.c\
$(LIBFT_DIR)/ft_strmapi.c\
$(LIBFT_DIR)/ft_striteri.c\
$(LIBFT_DIR)/ft_putchar_fd.c\
$(LIBFT_DIR)/ft_putstr_fd.c\
$(LIBFT_DIR)/ft_putendl_fd.c\
$(LIBFT_DIR)/ft_putnbr_fd.c\
$(LIBFT_DIR)/ft_lstnew.c\
$(LIBFT_DIR)/ft_lstget.c\
$(LIBFT_DIR)/ft_lstrot_front.c\
$(LIBFT_DIR)/ft_lstrot_back.c\
$(LIBFT_DIR)/ft_lstpop_front.c\
$(LIBFT_DIR)/ft_lstpop_back.c\
$(LIBFT_DIR)/ft_lstadd_front.c\
$(LIBFT_DIR)/ft_lstadd_back.c\
$(LIBFT_DIR)/ft_lstsize.c\
$(LIBFT_DIR)/ft_lstlast.c\
$(LIBFT_DIR)/ft_lstlast_back.c\
$(LIBFT_DIR)/ft_lstdelone.c\
$(LIBFT_DIR)/ft_lstclear.c\
$(LIBFT_DIR)/ft_lstiter.c\
$(LIBFT_DIR)/ft_lstmap.c\

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS =\
$(FT_PRINTF_DIR)/ft_printf.c\
$(FT_PRINTF_DIR)/ft_printf_ops.c\
$(FT_PRINTF_DIR)/temp_sprintf.c\
$(FT_PRINTF_DIR)/padding.c\
$(FT_PRINTF_DIR)/precision_int.c\
$(FT_PRINTF_DIR)/get_hex.c\
$(FT_PRINTF_DIR)/write_ops.c\
$(FT_PRINTF_DIR)/parse_spec.c\
$(FT_PRINTF_DIR)/print_char.c\
$(FT_PRINTF_DIR)/print_hex_lower.c\
$(FT_PRINTF_DIR)/print_hex_upper.c\
$(FT_PRINTF_DIR)/print_int.c\
$(FT_PRINTF_DIR)/print_percent.c\
$(FT_PRINTF_DIR)/print_ptr.c\
$(FT_PRINTF_DIR)/print_str.c\
$(FT_PRINTF_DIR)/print_uint.c\

GNL_DIR = get_next_line
GNL_SRCS =\
$(GNL_DIR)/get_next_line.c\

INCLUDES = -Iinclude
SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(LIBFT_SRCS:%.c=obj/%.o) $(FT_PRINTF_SRCS:%.c=obj/%.o) $(GNL_SRCS:%.c=obj/%.o)

all: $(NAME)
bonus: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS) obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
