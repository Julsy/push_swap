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

int		find_placement(int *stack, int len, int elem, char **rot_type)
{
	int i;
	int min;
	int max;
	int place;

	i = 0;
	place = 0;
	min = find_min_elem(stack, len);
	max = find_max_elem(stack, len);

	//printf("\nfind place in B for %d?\n", elem);
	//printf("stack[max=%d]=%d, stack[min=%d]=%d\n", max, stack[max], min, stack[min]);

	if (len == 2 && elem > stack[0] && elem < stack[len - 1])
		place = 0;
	else if (len == 2 && elem < stack[0] && elem > stack[len - 1])
		place = 1;
	else if (elem > stack[max] || elem < stack[min])
		place = max;
	while (i < len)
	{
		if(elem < stack[i] && elem > stack[i + 1])
		{
			place = i + 1;
			break ;
		}
		i++;
	}
	if (place < len / 2)
		*rot_type = ft_strcpy(*rot_type, "rb");
	else
	{
		place = len - place;
		*rot_type = ft_strcpy(*rot_type, "rrb");
	}
	//printf("place=%d\n", place);
	return (place);
}

int		where_to_insert(int *stack, int len, int elem, char **rot_type)
{
	int i;
	int min;
	int max;
	int place;

	i = 0;
	min = find_min_elem(stack, len);
	max = find_max_elem(stack, len);

	//printf("\nwhere to insert %d?\n", elem);

	if (len == 2 && elem > stack[0] && elem < stack[1])
		return (1);
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		return (0);
	else if (elem > stack[max] || elem < stack[min])
		place = min;

	while (i < len)
	{
		//printf("elem %d vs %d:%d\n", elem, stack[i], (i+1<len)?stack[i + 1]:stack[0]);
		if (elem > stack[i] && ((i + 1<len && elem < stack[i + 1]) || (i+1==len && elem < stack[0])))
		{
			place = i+1;
			break ;
		}
		i++;
	}
	if (place > len / 2)
	{
		*rot_type = ft_strcpy(*rot_type, "rra");
		//printf("standard return RRA %d\n", i);
		return (len - place);
	}
	else
	{
		*rot_type = ft_strcpy(*rot_type, "ra");
		//printf("standard return RA %d\n", len - i);
	}
	return (place);
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

	common = 0;
	if ((ft_strequ(moves->a_rot_type, "rra") && (ft_strequ(moves->b_rot_type , "rrb"))) ||
			(ft_strequ(moves->a_rot_type, "ra") && (ft_strequ(moves->b_rot_type , "rb"))))
	{
		common = num_cmp(moves->a_moves, moves->b_moves);
		if (common)
		{
			moves->common_rot = ft_strcpy(moves->common_rot, moves->a_rot_type);
			moves->common_rot[ft_strlen(moves->common_rot) - 1] = 'r';
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
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
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
			free_moves(best_move);
			best_move = moves;
		}
		else
			free_moves(moves);
		//printf("check best_move: elem %d, a: %d, b: %d, total: %d\n", stack->stack_a[i], moves->a_moves, moves->b_moves, moves->total);
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
		//printf("num of rots: %d\n", num_of_rots);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			num_of_rots--;
		}
		//ft_print_int_array(stack->stack_a, stack->a_size);
		apply_pa(stack);
		//ft_print_int_array(stack->stack_a, stack->a_size);
		//ft_print_int_array(stack->stack_b, stack->b_size);
	}
	place_smallest_first_a(stack);
	free(rot_type);
}

void		global_sort(t_stack *stack)
{
	t_moves *best_move;

	while (stack->b_size != 2)
		apply_pb(stack);
	//ft_print_int_array(stack->stack_a, stack->a_size);
	//ft_print_int_array(stack->stack_b, stack->b_size);
	while (stack->a_size > 2)
	{
		best_move = best_way_from_a_to_b(stack);
		//printf("best move chosen: %d\n", best_move->elem);
		//printf("common moves? %d\n", best_move->common_moves);
		while (best_move->common_moves)
		{
			if (ft_strequ(best_move->common_rot, "rr"))
				apply_rr(stack);
			else
				apply_rrr(stack);
			best_move->common_moves--;
		}
		while (best_move->a_moves)
		{
			if (ft_strequ(best_move->a_rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			best_move->a_moves--;
		}
		//printf("rotate b %d times\n", best_move->b_moves);
		while (best_move->b_moves)
		{
			if (ft_strequ(best_move->b_rot_type, "rb"))
				apply_rb(stack);
			else
				apply_rrb(stack);
			best_move->b_moves--;
		}
		apply_pb(stack);
//		ft_print_int_array(stack->stack_b, stack->b_size);
	}
	//ft_print_int_array(stack->stack_a, stack->a_size);
	//ft_print_int_array(stack->stack_b, stack->b_size);
	//printf("\nInserting back in A\n");
	insert_back_to_a(stack);
	free_moves(best_move);
}
