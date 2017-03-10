#include "push_swap.h"

static int		validate_args(char **argv, char *arg, int start)
{
	int i;

	i = -1;
	if (ft_atoi(arg) > INT32_MAX || ft_atoi(arg) < INT32_MIN)
		return (0);
	while (*arg && arg[++i] != '\0')
		if (arg[i] != '-' && !ft_isdigit(arg[i]))
			return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strequ(argv[start], arg))
		{
			printf("duplicates!\n");
			return (0);
		}
		start++;
	}
	return (1);
}

static void	init_stack_struct(t_stack *stack, int argc)
{
	stack->stack_a = (int *)malloc(sizeof(int) * argc);
	stack->stack_b = (int *)ft_memalloc(sizeof(int) * argc);
	stack->total_size = argc;
	stack->a_size = argc;
	stack->b_size = 0;
	stack->print = 1;
	stack->total_instr = 0;
}

t_stack		*parse_args(int argc, char **argv)
{
	int		i;
	t_stack *stack;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack_struct(stack, argc);
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->stack_a[i] = ft_atoi(argv[i]);
		else
			return (NULL);
		i++;
	}
	return (stack);
}
