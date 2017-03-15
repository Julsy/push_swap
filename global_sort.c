// 1. amount of instructions to put elem to the 0 position
// 2. find a place in B where to put elem (between min and max)
// 3. calculate total amount of instruction
// 4. do for all elems in A, then pick the one with least number => repeat

#include "push_swap.h"

int		all_the_way_front(int len, int pos, char **a_rot_type)
{
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		return (len - pos);
	}
	else
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
		return (pos);
	}
}

int		find_placement(int *stack, int len, int elem, char **b_rot_type)
{
	int i;

	printf("find placement: %d\n", elem);
	if (elem > stack[0] && find_max_elem(stack, len) == 0)
		return (0);
	else if (elem < stack[len - 1] && find_min_elem(stack, len) == len - 1)
		return (0);
	i = 0;
	while (i < len)
	{
		printf("%d vs %d:%d\n", elem, stack[i], stack[i + 1]);
		if (elem < stack[i] && elem > stack[i + 1])
		{
			if (i + 1 > len / 2)
				*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
			else
				*b_rot_type = ft_strcpy(*b_rot_type, "rb");
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int		where_to_insert(int *stack, int len, int elem, char **rot_type)
{
	int i;
	int min;
	int max;

	i = 0;
	min = find_min_elem(stack, len);
	max = find_max_elem(stack, len);

	printf("\nwhere to insert %d?\n", elem);

	if ((elem < stack[0] && min == 0) ||
		(elem > stack[len - 1] && max == len - 1))
		return (0);

	while (i < len)
	{
		printf("%d vs %d:%d or %d:%d\n", elem, stack[i], stack[i + 1], stack[i], stack[i - 1]);
		if ((elem < stack[i] && min == i) ||
			(elem > stack[i] && max == i))
		{
			if (i > len / 2)
				*rot_type = ft_strcpy(*rot_type, "ra"); ???
			else
				*rot_type = ft_strcpy(*rot_type, "rra"); ???
			printf("smaller than min/bigger than max: %d\n", i);
			return (i);
		}
		if (elem > stack[i] && elem < stack[i + 1])
		{
			if (i > len / 2)
				*rot_type = ft_strcpy(*rot_type, "ra");
			else
				*rot_type = ft_strcpy(*rot_type, "rra");
			printf("standard return %d\n", i + 1);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int 	num_cmp(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int		find_common(t_moves *moves)
{
	int		common;
	char	*shared;

	common = 0;
	shared = ft_strnew(3);
	if ((ft_strequ(moves->a_rot_type, "rra") && (ft_strequ(moves->b_rot_type , "rrb"))) ||
			(ft_strequ(moves->a_rot_type, "ra") && (ft_strequ(moves->b_rot_type , "rb"))))
	{
		common = num_cmp(moves->a_moves, moves->b_moves);
		if (!common)
		{
			shared = ft_strcpy(shared, moves->a_rot_type);
			shared[ft_strlen(shared) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->a_rot_type = ft_strnew(3);
	moves->b_rot_type = ft_strnew(3);
	moves->common_rot = ft_strnew(3);
	moves->elem = stack->stack_a[pos];
	moves->a_moves = all_the_way_front(stack->a_size, pos, &(moves->a_rot_type));
	moves->b_moves = find_placement(stack->stack_b, stack->b_size, stack->stack_a[pos], &(moves->b_rot_type));
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + 1;
	return (moves);
}

t_moves	*best_way_from_a_to_b(t_stack *stack)
{
	int		i;
	t_moves *best_move;
	t_moves *moves;

	i = 0;
	while (i < stack->a_size)
	{
		moves = calc_moves_from_a_to_b(stack, i);
		if (i == 0)
			best_move = moves;
		else if (best_move->total > moves->total)
		{
			free(best_move);
			best_move = moves;
		}
		else
			free(moves);
		printf("check best_move: elem %d, a: %d, b: %d, total: %d\n", stack->stack_a[i], moves->a_moves, moves->b_moves, moves->total);
		i++;
	}
	return (best_move);
}

void	insert_back_to_a(t_stack *stack)
{
	int num_of_rots;
	char *rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (stack->b_size)
	{
		num_of_rots = where_to_insert(stack->stack_a, stack->a_size, stack->stack_b[0], &rot_type);
		printf("num of rots: %d\n", num_of_rots);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			num_of_rots--;
		}
		ft_print_int_array(stack->stack_a, stack->a_size);
		apply_pa(stack);
		ft_print_int_array(stack->stack_a, stack->a_size);
		ft_print_int_array(stack->stack_b, stack->b_size);
	}
	while (!is_sorted(stack->stack_a, stack->a_size))
		place_smallest_first_a(stack);
	free(rot_type);
}

void		global_sort(t_stack *stack)
{
	t_moves *best_move;

	while (stack->b_size != 2)
	{
		apply_pb(stack);
		place_biggest_first_b(stack);
	}
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	while (stack->a_size > 2)
	{
		best_move = best_way_from_a_to_b(stack);
		printf("best move chosen: %d\n", best_move->elem);
		printf("common moves? %d\n", best_move->common_moves);
		while (best_move->common_moves)
		{
			if (ft_strequ(best_move->common_rot, "rr"))
				apply_rr(stack);
			else
				apply_rrr(stack);
		}
		while (best_move->a_moves)
		{
			if (ft_strequ(best_move->a_rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			best_move->a_moves--;
		}
		printf("rotate b %d times\n", best_move->b_moves);
		while (best_move->b_moves)
		{
			if (ft_strequ(best_move->a_rot_type, "rb"))
				apply_rb(stack);
			else
				apply_rrb(stack);
			best_move->b_moves--;
		}
		apply_pb(stack);
		ft_print_int_array(stack->stack_b, stack->b_size);
		place_biggest_first_b(stack);
	}
	place_smallest_first_a(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	printf("Inserting back in A\n");
	insert_back_to_a(stack);
	free(best_move);
}



