#include "push_swap.h"

static int 	find_min_index(int *stack, int len)
{
	int i;
	int tmp;
	int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int 	find_max_index(int *stack, int len)
{
	int i;
	int tmp;
	int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_min_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_max_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_a(t_stack *stack)
{
	int 	min_index;

	min_index = find_min_index(stack->stack_a, stack->a_size);
	if (min_index <= stack->a_size / 2)
		while (min_index--)
			apply_ra(stack);
	else
		while ((stack->a_size - min_index) > 0)
		{
			apply_rra(stack);
			min_index++;
		}
}

void	place_biggest_first_b(t_stack *stack)
{
	int 	max_index;

	while ((max_index = find_max_index(stack->stack_b, stack->b_size)) != 0)
	{
		if (max_index <= stack->b_size / 2)
			apply_rb(stack);
		else
			apply_rrb(stack);
	}
}

void	place_biggest_first_a(t_stack *stack)
{
	int 	max_index;

	while ((max_index = find_max_index(stack->stack_a, stack->a_size)) != 0)
	{
		if (max_index <= stack->a_size / 2)
			apply_ra(stack);
		else
			apply_rra(stack);
	}
}


// void	easy_sort(t_stack *stack)
// {
// 	while (stack->a_size > 0)
// 	{
// 		place_smallest_first_a(stack);
// 		apply_pb(stack);
// 	}
// 	while (stack->b_size > 0)
// 		apply_pa(stack);
// }

// void	sort_3(t_stack *stack)
// {
// 	if (stack->stack_a[0] > stack->stack_a[1])
// 			apply_sa(stack);
// 	if (!(is_sorted(stack->stack_a, stack->a_size)) &&
// 		stack->stack_a[1] > stack->stack_a[2])
// 		apply_rra(stack);
// 	if (!(is_sorted(stack->stack_a, stack->a_size)))
// 		apply_sa(stack);
// 	place_smallest_first_a(stack);
// }

// void	sort_5(t_stack *stack)
// {
// 	apply_pb(stack);
// 	apply_pb(stack);
// 	sort_3(stack);
// 	insert_back_to_a(stack);
// }

// void	sort_4(t_stack *stack)
// {
// 	apply_pb(stack);
// 	sort_3(stack);
// 	insert_back_to_a(stack);
// }

void	merge_sort_a(t_stack *stack)
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

void	merge_sort_b(t_stack *stack)
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

void	merge_sort(t_stack *stack)
{
	place_biggest_first_a(stack);
	while (stack->a_size > 3)
		apply_pb(stack);
	merge_sort_a(stack);
	merge_sort_b(stack);
	insert_back_to_a(stack);
	place_smallest_first_a(stack);
}

void	sort(t_stack *stack)
{
	// if (is_sorted(stack->stack_a, stack->a_size) && stack->b_size == 0)
	// 	return ;
	if (stack->a_size <= 5)
		return (merge_sort(stack));
	else
		global_sort(stack);
}
