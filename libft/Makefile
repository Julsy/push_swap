# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 17:42:31 by iiliuk            #+#    #+#              #
#    Updated: 2017/03/02 10:09:04 by iiliuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf.c helper.c get_flags.c process_char.c process_ptr.c \
process_digit_id.c process_digit_oux.c process_percent.c process_width.c \
process_precision.c process_wide_char.c

LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_list_size.c ft_list_add_back.c ft_list_last.c \
ft_list_push_params.c ft_list_nth.c ft_list_reverse.c ft_realloc.c ft_abs.c \
ft_itoa_base.c ft_strndup.c ft_itoa_unbase.c ft_lstdelcont.c ft_lst_free_cont.c \
ft_print_list.c get_next_line.c ft_print_int_array.c

.PHONY: all clean fclean re

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NC			=	\033[0m

OBJSFD = objects

FT_PRINTF_SRCS = $(addprefix srcs/ft_printf/,$(FT_PRINTF))

LIBFT_SRCS = $(addprefix srcs/,$(LIBFT))

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS)

OBJECTS = $(LIBFT:.c=.o) $(FT_PRINTF:.c=.o)

OBJS = $(addprefix $(OBJSFD)/, $(OBJECTS))

VPATH =	srcs:srcs/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)compiling binary...$(NC)"
	@ar src $@ $(OBJS)
	@ranlib $@
	@echo "$(GREEN)libft.a is created$(NC)"

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@

HDR = -I./includes

clean:
	@echo "$(RED)deleting libft object files...$(NC)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)

fclean: clean
	@echo "$(RED)deleting the library...$(NC)"
	@/bin/rm -f $(NAME)

re: fclean all
