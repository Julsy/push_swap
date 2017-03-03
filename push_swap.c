#include "push_swap.h"

static int	validate_args(char **argv, char *arg, int start)
{
	int i;

	i = -1;
	if (ft_atoi(arg) > INT32_MAX || ft_atoi(arg) < INT32_MIN)
		return (0);
	while (*arg && arg[++i] != '\0')
		if (!ft_isdigit(arg[i]))
			return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strnstr(argv[start], arg, ft_strlen(arg)))
			return (0);
		start++;
	}
	return (1);
}

void		init_stack_struct(t_stack *stack, int argc)
{
	stack->stack_a = (int *)malloc(sizeof(int) * argc);
	stack->stack_b = (int *)ft_memalloc(sizeof(int) * argc);
	stack->total_size = argc;
	stack->a_size = argc;
	stack->b_size = 0;
}

t_stack		*parse_args(int argc, char **argv)
{
	int		i;
	t_stack *stack;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack_struct(stack, argc);
	while (++i <= argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->stack_a[i - 1] = ft_atoi(argv[i]);
		else
			return (0);
	}
	return (stack);
}

int			main(int argc, char **argv)
{
	t_stack *stack;

	if (argc <= 1)
		exit(0);
	stack = parse_args(argc - 1, argv);
	ft_print_int_array(stack->stack_a, stack->a_size);
	stack->stack_b[0] = 1;
	stack->stack_b[1] = 3;
	stack->stack_b[2] = 5;
	stack->stack_b[3] = 0;
	stack->b_size = 4;
	ft_print_int_array(stack->stack_b, stack->b_size);
	apply_pa(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	// sort_stacks();
	// exec_commands();
	// free(stack);
	return (0);
}
