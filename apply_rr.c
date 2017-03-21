/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/21 14:36:37 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	apply_ra(t_stack *stack)
{
	int i;
	int tmp;

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
	ft_printf("ra\n");
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

void 	apply_rb(t_stack *stack)
{
	int i;
	int tmp;

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
	ft_printf("rb\n");
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

void 	apply_rr(t_stack *stack)
{
	int tmp;

	tmp = stack->print;
	stack->print = 0;
	apply_ra(stack);
	apply_rb(stack);
	stack->print = tmp;
	ft_printf("rr\n");
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
