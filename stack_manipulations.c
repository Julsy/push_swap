#include "push_swap.h"

int		is_sorted(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->b_size == 0)
	{
		while (i < stack->a_size - 1)
		{
			if (stack->stack_a[i] < stack->stack_a[i + 1])
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (-1);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	stack = NULL;
}
