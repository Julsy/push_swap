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

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	stack = NULL;
}
