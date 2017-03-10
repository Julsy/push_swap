# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 12:28:41 by iiliuk            #+#    #+#              #
#    Updated: 2017/03/09 16:32:52 by iiliuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= push_swap.c parse_args.c apply_instr.c easy_sort.c stack_manipulations.c

SRC2 	= checker.c parse_args.c apply_instr.c easy_sort.c stack_manipulations.c

.PHONY: all clean fclean re

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

OBJSFD 	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))
OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

$(LIBFT):
	@make -C libft re

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJS1) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(NAME2): $(OBJS2) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJS2) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./libft clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NC)"
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./libft fclean

re: fclean all
