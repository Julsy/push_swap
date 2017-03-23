/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:26:09 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/23 12:22:05 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_args(char **argv, char *arg, int start)
{
	register int i;

	i = 0;
	while (*arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strequ(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

void		init_stack_struct(t_stack *stack, int argc)
{
	stack->stack_a = (int *)malloc(sizeof(int) * argc);
	stack->stack_b = (int *)ft_memalloc(sizeof(int) * argc);
	stack->a_size = argc;
	stack->b_size = 0;
	stack->total_instr = 0;
	stack->print_instr = 1;
}

int			parse_options(int *argc, char ***argv, t_stack *stack)
{
	register int i;

	i = 0;
	stack->total = 0;
	stack->color = 0;
	stack->print_stack = 0;
	while (i < *argc && *((*argv)[i]) == '-')
	{
		if (ft_strequ((*argv)[i], "-v"))
			stack->print_stack = 1;
		else if (ft_strequ((*argv)[i], "-t"))
			stack->total = 1;
		else if (ft_strequ((*argv)[i], "-c"))
			stack->color = 1;
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("usage: ./push_swap [-v -c -t] [numbers...]\n", 2);
			exit(1);
		}
		i++;
	}
	*argc -= i;
	*argv += i;
	return (i);
}

t_stack		*parse_args(int argc, char **argv, t_stack *stack)
{
	register int i;
	
	i = 0;
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->stack_a[i] = ft_atoi(argv[i]);
		else
		{
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
