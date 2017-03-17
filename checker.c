/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:00:39 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/16 19:13:13 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_instruction(t_stack *stack, char *instr)
{
	if (ft_strequ(instr, "sa"))
		apply_sa(stack);
	else if (ft_strequ(instr, "sb"))
		apply_sb(stack);
	else if (ft_strequ(instr, "ss"))
		apply_ss(stack);
	else if (ft_strequ(instr, "pa"))
		apply_pa(stack);
	else if (ft_strequ(instr, "pb"))
		apply_pb(stack);
	else if (ft_strequ(instr, "ra"))
		apply_ra(stack);
	else if (ft_strequ(instr, "rb"))
		apply_rb(stack);
	else if (ft_strequ(instr, "rr"))
		apply_rr(stack);
	else if (ft_strequ(instr, "rra"))
		apply_rra(stack);
	else if (ft_strequ(instr, "rrb"))
		apply_rrb(stack);
	else if (ft_strequ(instr, "rrr"))
		apply_rrr(stack);
	else
		return (-1);
	return (0);
}

void		do_instruction(t_stack *stack)
{
	char 	*instr;

	while (get_next_line(0, &instr) > 0)
	{
		if (ft_strequ(instr, ""))
			break ;
		if (get_instruction(stack, instr))
		{
			free(instr);
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(instr);
	}
	free(instr);
}

int			main(int argc, char **argv)
{
	t_stack *stack;
	int		options;
	(argc-- == 1) ? exit(0) : argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	options = parse_options(argc, argv, stack);
	argc -= options;
	argv += options;
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		if (argc == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	init_stack_struct(stack, argc);
	stack = parse_args(argc, argv, stack);
	//ft_print_int_array(stack->stack_a, stack->a_size);
	stack->print=0;
	if (!(is_sorted(stack->stack_a, stack->a_size)))
		do_instruction(stack);
	//ft_print_int_array(stack->stack_a, stack->a_size);
	if (is_sorted(stack->stack_a, stack->a_size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (stack)
		free_stack(stack);
	return (0);
}
