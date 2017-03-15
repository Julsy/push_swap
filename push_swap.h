/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:59:28 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/13 10:57:42 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
// DELETE ME !!!!!!!!!!
#include <stdio.h>

typedef struct	s_stack
{
	int 		*stack_a;
	int 		*stack_b;
	int			total_size;
	int			a_size;
	int			b_size;
	int			print;
	int			total_instr;
}				t_stack;

typedef struct	s_moves
{
	int			elem;
	int			a_moves;
	char		*a_rot_type;
	char		*b_rot_type;
	char		*common_rot;
	int			b_moves;
	int			common_moves;
	int			total;
}				t_moves;

void 	apply_sa(t_stack *stack);
void 	apply_sb(t_stack *stack);
void 	apply_ss(t_stack *stack);
void 	apply_pa(t_stack *stack);
void 	apply_pb(t_stack *stack);
void 	apply_ra(t_stack *stack);
void 	apply_rb(t_stack *stack);
void 	apply_rr(t_stack *stack);
void 	apply_rra(t_stack *stack);
void 	apply_rrb(t_stack *stack);
void 	apply_rrr(t_stack *stack);

void	easy_sort(t_stack *stack);
void	sort(t_stack *stack);
void	global_sort(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack);
void	merge_sort(t_stack *stack);
void	place_smallest_first(t_stack *stack);
int 	find_min_elem(int *stack, int stack_len);
int 	find_max_elem(int *stack, int stack_len);
void	place_smallest_first_a(t_stack *stack);
void	place_smallest_first_b(t_stack *stack);
void	place_biggest_first_b(t_stack *stack);
void	insert_back_to_a(t_stack *stack);
int		where_to_insert(int *stack, int len, int elem, char **rot_type);

int		is_sorted(int *stack, int len);
void	free_stack(t_stack *stack);

t_stack	*parse_args(int argc, char **argv);

void	push_to_b(t_stack *stack);

#endif

/*
**	Check for errors:
**	1. non-numeric parameters
**	2. greater than MAXINT
**	3. duplicates
**	4. no parameters (must not display anything and give the prompt back)
**	5. invalid instruction
**	6. instruction with spaces around (must be only \n at the end)
**	
**	CHEKER
**	Checker stops after  CTRL+D command
**	Takes the list of commands from push_swap (stdin - use GNL??)
**	List of ints from argv
**	Error check
**	Executes commands on a given list of ints
**	Returns OK (if list is sorted) / KO (if it's not) or Error
**	If given an already sorted list of ints and no commands - should display OK
**	
**	PUSH_SWAP
**	Validate args
**	Create stacks structures
**	Calculate possibilities
**	Uses algorithm according to the amount of numbers
**	Executes commands to sort the stack
**	Returns list of commands (or prints on screen)
**
**	if given 1 number as argv or already sorted list - should display no commands
*/
