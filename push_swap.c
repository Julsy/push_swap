/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:12:53 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/16 19:14:31 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stack;
	int		options;

	(argc-- == 1) ? exit(0) : argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	options = parse_options2(&argc, &argv, stack);
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
	sort(stack);
	//ft_print_int_array(stack->stack_a, stack->a_size);
	//printf("Total: %d\n", stack->total_instr);
	free_stack(stack);
	return (0);
}
