/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/22 16:49:54 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	apply_rra(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->a_size == 0)
		return ;
	i = stack->a_size - 1;
	tmp = stack->stack_a[i];
	while (i > 0) 
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	stack->print_instr ? ft_printf("rra\n") : 0;
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

void 	apply_rrb(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->b_size == 0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->stack_b[i];
	while (i > 0) 
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	stack->print_instr ? ft_printf("rrb\n") : 0;
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

void 	apply_rrr(t_stack *stack)
{
	register int tmp_instr;
	register int tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->print_stack = 0;
	apply_rra(stack);
	apply_rrb(stack);
	stack->print_instr = tmp_instr;
	stack->print_stack = tmp_stack;
	stack->print_instr ? ft_printf("rrr\n") : 0;
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

