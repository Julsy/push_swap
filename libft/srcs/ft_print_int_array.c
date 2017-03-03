/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:08:26 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/02 15:28:14 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_array(int *array, int arr_size)
{
	int i;

	i = 0;
	if (arr_size > 0)
		ft_putchar('[');
	while (i < arr_size)
	{
		if (i + 1 == arr_size)
		{
			ft_putnbr(array[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(array[i]);
			ft_putstr(", ");
		}
		i++;
	}
}
