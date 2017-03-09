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
		{
			printf("rra\n");
			apply_rra(stack);
		}
		else
		{
			printf("ra\n");
			apply_ra(stack);
		}
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
