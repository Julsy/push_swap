/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:11:31 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/16 16:11:35 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		is_reverse_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	stack = NULL;
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}
