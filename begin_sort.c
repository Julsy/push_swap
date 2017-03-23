/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:58:59 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/22 16:50:03 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *stack)
{
	register int max_idx;

	if (stack->a_size == 1)
		return ;
	if (stack->a_size == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
		return ;
	}
	else if (stack->a_size == 3)
	{
		max_idx = find_max_elem(stack->stack_a, stack->a_size);
		if (max_idx == 0)
			apply_ra(stack);
		if (max_idx == 1)
			apply_rra(stack);
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
	}
}

void		sort(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->a_size) && stack->b_size == 0)
		return ;
	if (stack->print_stack)
	{
		stack->color ? ft_putstr(MAG) : 0;
		ft_printf("Pre-sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		stack->color ? ft_putstr(CYAN) : 0;
	}
	if (stack->a_size <= 3)
		return (sort_3(stack));
	else
		global_sort(stack);
	if (stack->print_stack)
	{
		stack->color ? ft_putstr(MAG) : 0;
		ft_printf("Sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
	}
	if (stack->total)
	{
		stack->color ? ft_putstr(BLUE) : 0;
		ft_printf("Total %d operations\n", stack->total_instr);
		stack->color ? ft_putstr(NC) : 0;
	}
}
