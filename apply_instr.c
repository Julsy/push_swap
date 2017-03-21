/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:12:24 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/21 14:36:55 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	apply_sa(t_stack *stack)
{
	int tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	ft_printf("sa\n");
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

void 	apply_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	ft_printf("sb\n");
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

void 	apply_ss(t_stack *stack)
{
	int tmp;

	tmp = stack->print;
	stack->print = 0;
	apply_sa(stack);
	apply_sb(stack);
	stack->print = tmp;
	ft_printf("ss\n");
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

void 	apply_pa(t_stack *stack)
{
	int i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i-- > 0)
		stack->stack_a[i + 1] = stack->stack_a[i];
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i++ <= stack->b_size)
		stack->stack_b[i - 1] = stack->stack_b[i];
	stack->a_size++;
	stack->b_size--;
	ft_printf("pa\n");
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

void 	apply_pb(t_stack *stack)
{
	int i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i-- > 0)
		stack->stack_b[i + 1] = stack->stack_b[i];
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i++ <= stack->a_size - 1)
		stack->stack_a[i - 1] = stack->stack_a[i];
	stack->b_size++;
	stack->a_size--;
	ft_printf("pb\n");
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
