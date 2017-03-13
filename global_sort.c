// 1. amount of instructions to put elem to the 0 position
// 2. find a place in B where to put elem (between min and max)
// 3. calculate total amount of instruction
// 4. do for all elems in A, then pick the one with least number => repeat

#include "push_swap.h"

int		all_the_way_front(int len, int pos)
{
	if (pos > len / 2)
		len=1;//just temp, add ra or rra
//		return (len - pos);
//	else
		return (pos);
}

int		find_placement(int *stack, int len, int elem)
{
	int i;

	printf("%d\n", elem);
	if (elem < stack[0] )//&& elem is minimal
		return (0);
	else if (elem > stack[len - 1]) //and stack[len-1] is maximum
		return (len - 1);
	i = 0;
	while (i < len)
	{
		printf("%d vs %d:%d\n", elem, stack[i], stack[i+1]);
		if (elem > stack[i] && elem < stack[i + 1])
			return (i+1);
		i++;
	}
	return (0);
}

t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->elem = stack->stack_a[pos];
	moves->a_moves = all_the_way_front(stack->a_size, pos);
	moves->b_moves = find_placement(stack->stack_b, stack->b_size, stack->stack_a[pos]);
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
		printf("check best_move: %d, %d, %d\n", stack->stack_a[i], moves->a_moves, moves->b_moves);
		i++;
	}
	return (best_move);
}

static int 	find_min_elem(t_stack *stack)
{
	int i;
	int tmp;
	int index;

	if (stack->b_size == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack->stack_b[i];
	while (i < stack->b_size) 
	{
		if (tmp > stack->stack_b[i])
		{
			tmp = stack->stack_b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_b(t_stack *stack)
{
	int 	min_index;

	while ((min_index = find_min_elem(stack)) > 0)
	{
		if (min_index <= stack->b_size / 2)
			apply_rrb(stack);
		else
			apply_rb(stack);
	}
}

void	push_to_b(t_stack *stack)
{
	t_moves *best_move;

	apply_pb(stack);
	apply_pb(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	while (stack->a_size > 0)
	{
		best_move = best_way_from_a_to_b(stack);
		printf("1: %d\n", best_move->a_moves);
		while (best_move->a_moves)
		{
			apply_ra(stack);
			best_move->a_moves--;
		}
		printf("2: %d\n", best_move->b_moves);
		while (best_move->b_moves)
		{
			apply_rrb(stack);//!
			best_move->b_moves--;
		}
		printf("3\n");
		apply_pb(stack);
		place_smallest_first_b(stack);
		ft_print_int_array(stack->stack_a, stack->a_size);
		ft_print_int_array(stack->stack_b, stack->b_size);
	}
	place_smallest_first(stack);
	ft_print_int_array(stack->stack_a, stack->a_size);
	ft_print_int_array(stack->stack_b, stack->b_size);
	printf("\n");
	while (stack->b_size)
		apply_pa(stack);
	free(best_move);
}



