/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/22 16:49:42 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	apply_ra(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->a_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_a[0];
	while (i < stack->a_size) 
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	stack->print_instr ? ft_printf("ra\n") : 0;
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}

void 	apply_rb(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->b_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_b[0];
	while (i < stack->b_size) 
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	stack->print_instr ? ft_printf("rb\n") : 0;
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}

void 	apply_rr(t_stack *stack)
{
	register int tmp_instr;
	register int tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->print_stack = 0;
	apply_ra(stack);
	apply_rb(stack);
	stack->print_instr = tmp_instr;
	stack->print_stack = tmp_stack;
	stack->print_instr ? ft_printf("rr\n") : 0;
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}
