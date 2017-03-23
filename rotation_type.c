#include "push_swap.h"

int		find_a_rot_type(int len, int pos, char **a_rot_type)
{	
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
	return (pos);
}

int		find_b_rot_type(int len, int pos, char **b_rot_type)
{	
	if (pos > len / 2)
	{
		*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot_type = ft_strcpy(*b_rot_type, "rb");
	return (pos);
}
