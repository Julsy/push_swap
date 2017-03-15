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

	while ((min_index = find_min_index(stack->stack_a, stack->a_size)) != 0)
	{
		if (min_index <= stack->a_size / 2)
			apply_rra(stack);
		else
			apply_ra(stack);
	}
}

void	place_smallest_first_b(t_stack *stack)
{
	int 	min_index;

	while ((min_index = find_min_index(stack->stack_b, stack->b_size)) != 0)
	{
		if (min_index <= stack->b_size / 2)
			apply_rrb(stack);
		else
			apply_rb(stack);
	}
}

void	place_biggest_first_b(t_stack *stack)
{
	int 	max_index;

	while ((max_index = find_max_index(stack->stack_b, stack->b_size)) != 0)
	{
		if (max_index < stack->b_size / 2)
			apply_rb(stack);
		else
			apply_rrb(stack);
	}
}

void	easy_sort(t_stack *stack)
{
	while (stack->a_size > 0)
	{
		place_smallest_first_a(stack);
		apply_pb(stack);
	}
	while (stack->b_size > 0)
		apply_pa(stack);
}

void	sort_3(t_stack *stack)
{
	while (!(is_sorted(stack->stack_a, stack->a_size)))
	{
		place_smallest_first_a(stack);
		if (stack->stack_a[1] > stack->stack_a[2])
			apply_ra(stack);
		else
			apply_rra(stack);
		apply_sa(stack);
	}
}

void	sort_5(t_stack *stack)
{
	apply_pb(stack);
	apply_pb(stack);
	sort_3(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	insert_back_to_a(stack);
}

void	merge_sort_a(t_stack *stack)
{
	int max_idx;
	
	max_idx = find_max_elem(stack->stack_a, stack->a_size);
	if (max_idx == 0)
		apply_rra(stack);
	if (max_idx == 1)
		apply_ra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		apply_sa(stack);
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
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sb(stack);
	}
}

void	merge_sort(t_stack *stack)
{
	int min, max;

	while (stack->a_size > 3)
		apply_pb(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);

	//merge_sort_a(stack);
	sort_3(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);

	merge_sort_b(stack);
	ft_print_int_array(stack->stack_b, stack->b_size);

	while (stack->b_size > 0)
	{
		min=find_min_elem(stack->stack_a, stack->a_size);
		max=find_max_elem(stack->stack_a, stack->a_size);
		printf("%d, %d, %d, %d\n", stack->stack_b[0], stack->stack_a[max], stack->stack_a[0], stack->stack_a[min]);
		if((stack->stack_b[0] < stack->stack_a[0]) ||
			(stack->stack_b[0] > stack->stack_a[max] && stack->stack_a[0] == stack->stack_a[min]))
			apply_pa(stack);
		apply_rra(stack); 
		ft_print_int_array(stack->stack_a, stack->a_size);
		ft_print_int_array(stack->stack_b, stack->b_size);
	}
	place_smallest_first_a(stack);
}

void	sort(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->a_size) && !(stack->b_size == 0))
		return ;
	else if (stack->total_size == 2)
		return (apply_sa(stack));
	else if (stack->total_size == 3)
		return (sort_3(stack));
	else if (stack->total_size == 5)
		return (sort_5(stack));
	else
		global_sort(stack);
}
