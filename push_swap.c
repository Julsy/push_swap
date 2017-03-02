#include "push_swap.h"
#include <stdio.h>

void		print_int_array(int *array)
{
	int i = 0;
	while (array[i] != '\0')
		printf("%d\n", array[i]);
	i++;
} 

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
	stack->stack_a = (int *)malloc(sizeof(int));
	stack->stack_b = (int *)malloc(sizeof(int));
	stack->total_size = argc;
	stack->stack_a_size = argc;
	stack->stack_b_size = 0;
}

t_stack		*parse_args(int argc, char **argv)
{
	int		i;
	t_stack *stack;

	if (argc <= 1)
		exit(0);
	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack_struct(stack, argc);
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
		{
			stack->stack_a[i] = ft_atoi(argv[i]);
			printf("i: %d, %d\n", i, stack->stack_a[i]);
		}
		else
			return (0);
		i++;
	}
	print_int_array(stack->stack_a);
	return (0);
}

int			main(int argc, char **argv)
{
	parse_args(argc, argv);
	// error_check(stack);
	// sort_stacks();
	// exec_commands();
	// free(stack);
	return (0);
}
