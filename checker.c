#include "push_swap.h"

static int	get_instruction(t_stack *stack, char *instr)
{
	if (ft_strequ(instr, "sa"))
		apply_sa(stack);
	else if (ft_strequ(instr, "sb"))
		apply_sb(stack);
	else if (ft_strequ(instr, "ss"))
		apply_ss(stack);
	else if (ft_strequ(instr, "pa"))
		apply_pa(stack);
	else if (ft_strequ(instr, "pb"))
		apply_pb(stack);
	else if (ft_strequ(instr, "ra"))
		apply_ra(stack);
	else if (ft_strequ(instr, "rb"))
		apply_rb(stack);
	else if (ft_strequ(instr, "rr"))
		apply_rr(stack);
	else if (ft_strequ(instr, "rra"))
		apply_rra(stack);
	else if (ft_strequ(instr, "rrb"))
		apply_rrb(stack);
	else if (ft_strequ(instr, "rrr"))
		apply_rrr(stack);
	else
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack *stack;
	char 	*instr;

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
	stack->print = 0;
	while (get_next_line(0, &instr) > 0)
	{
		if (ft_strequ(instr, ""))
			break ;
		if (get_instruction(stack, instr))
		{
			free(instr);
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(instr);
	}
	free(instr);
	ft_print_int_array(stack->stack_a, stack->a_size);
	if (is_sorted(stack))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack);
	return (0);
}
