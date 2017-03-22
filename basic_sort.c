/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:58:59 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/21 15:14:20 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	basic_sort_a(t_stack *stack)
{
	int max_idx;

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

static void	basic_sort_b(t_stack *stack)
{
	int max_idx;

	if (stack->b_size == 1)
		return ;
	if (stack->b_size == 2)
	{
		if (stack->stack_b[0] > stack->stack_b[1])
			apply_sb(stack);
		return ;
	}
	else if (stack->b_size == 3)
	{
		max_idx = find_max_elem(stack->stack_b, stack->b_size);
		if (max_idx == 0)
			apply_rrb(stack);
		if (max_idx == 1)
			apply_rb(stack);
		if (stack->stack_b[0] > stack->stack_b[1])
			apply_sb(stack);
	}
}

void		basic_sort(t_stack *stack)
{
	place_biggest_first_a(stack);
	while (stack->a_size > 3)
		apply_pb(stack);
	basic_sort_a(stack);
	basic_sort_b(stack);
	insert_back_to_a(stack);
	place_smallest_first_a(stack);
}

void		sort(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->a_size) && stack->b_size == 0)
		return ;
	if (stack->print_stack)
	{
		ft_printf("Pre-sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
	}
	if (stack->a_size <= 5)
		return (basic_sort(stack));
	else
		global_sort(stack);
	if (stack->print_stack)
	{
		ft_printf("Sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
	}
	if (stack->total)
		ft_printf("Total %d operations\n", stack->total_instr);
}
