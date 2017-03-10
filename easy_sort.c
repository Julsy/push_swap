#include "push_swap.h"

static int 	find_min_elem(t_stack *stack)
{
	int i;
	int tmp;
	int index;

	if (stack->a_size == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack->stack_a[i];
	while (i < stack->a_size) 
	{
		if (tmp > stack->stack_a[i])
		{
			tmp = stack->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	place_smallest_first(t_stack *stack)
{
	int 	min_index;

	while ((min_index = find_min_elem(stack)) > 0)
	{
		if (min_index <= stack->a_size / 2)
			apply_rra(stack);
		else
			apply_ra(stack);
	}
}

void	easy_sort(t_stack *stack)
{
	while (stack->a_size > 0)
	{
		place_smallest_first(stack);
		apply_pb(stack);
	}
	while (stack->b_size > 0)
		apply_pa(stack);
}

void	sort_3(t_stack *stack)
{
	place_smallest_first(stack);
	while (!(is_sorted(stack)))
	{
		if (stack->stack_a[1] > stack->stack_a[2])
			apply_ra(stack);
		else
			apply_rra(stack);
		apply_sa(stack);
	}
}

void	sort_5(t_stack *stack)
{
	while (!(is_sorted(stack)))
	{
		place_smallest_first(stack);
		if (stack->stack_a[1] > stack->stack_a[2])
			apply_ra(stack);
		else
			apply_rra(stack);
		// if (stack->stack_a[0] > stack->stack_a[1])
		// 	apply_sa(stack);
	}
}

void	sort(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	else if (stack->total_size == 2)
		return (apply_sa(stack));
	else if (stack->total_size == 3)
		return (sort_3(stack));
	else if (stack->total_size == 5)
		return (sort_5(stack));
	else
		easy_sort(stack);
}
