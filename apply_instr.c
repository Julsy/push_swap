/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:12:24 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/03 19:08:47 by iiliuk           ###   ########.fr       */
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
}

void 	apply_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void 	apply_ss(t_stack *stack)
{
	apply_sa(stack);
	apply_sb(stack);
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
}

void 	apply_ra(t_stack *stack)
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
}

void 	apply_rb(t_stack *stack)
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
}

void 	apply_rr(t_stack *stack)
{
	apply_ra(stack);
	apply_rb(stack);
}

void 	apply_rra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->a_size == 0)
		return ;
	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->a_size) 
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
}

void 	apply_rrb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->b_size == 0)
		return ;
	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->b_size) 
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
}

void 	apply_rrr(t_stack *stack)
{
	apply_rra(stack);
	apply_rrb(stack);
}

