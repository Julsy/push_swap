/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:12:24 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/02 17:12:42 by iiliuk           ###   ########.fr       */
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
	int tmp;
	int i;

	printf("here\n");
	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i > 0)
	{
		//printf("tmp: %d, stack[i]: %d, stack[i + 1]: %d\n", tmp, stack->stack_a[i], stack->stack_a[i + 1]);
		tmp = stack->stack_a[i];
		stack->stack_a[i] = stack->stack_a[i - 1];
		stack->stack_a[i - 1] = tmp;
		printf("tmp: %d, stack[%d]: %d, stack[%d + 1]: %d\n", tmp, i, stack->stack_a[i], i, stack->stack_a[i + 1]);
		// printf("%d\n", stack->stack_a[i]);
		// stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->b_size)
	{
		tmp = stack->stack_b[i - 1];
		stack->stack_b[i - 1] = stack->stack_b[i];
		stack->stack_b[i] = tmp;
		printf("\ntmp: %d, stack[%d - 1]: %d, stack[%d]: %d\n", tmp, i, stack->stack_b[i - 1], i, stack->stack_b[i]);
		i++;
	}
	stack->a_size++;
	stack->b_size--;
}
