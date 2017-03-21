/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/21 14:36:25 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	apply_rra(t_stack *stack)
{
	int i;
	int tmp;

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
	ft_printf("rra\n");
	if (stack->print)
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
	int i;
	int tmp;

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
	ft_printf("rrb\n");
	if (stack->print)
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
	int tmp;

	tmp = stack->print;
	stack->print = 0;
	apply_rra(stack);
	apply_rrb(stack);
	stack->print = tmp;
	ft_printf("rrr\n");
	if (stack->print)
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

