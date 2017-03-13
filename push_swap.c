#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack *stack;

	(argc-- == 1) ? exit(0) : argv++;
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		(argc == 0) ? ft_printf("Error\n") : (0);
	}
	stack = parse_args(argc, argv);
	if(!stack)
		return (-1);
	ft_print_int_array(stack->stack_a, stack->a_size);
	//merge_sort(stack);
	push_to_b(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	printf("Total: %d\n", stack->total_instr);
	// exec_commands();
	free(stack);
	return (0);
}
