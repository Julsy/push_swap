/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 17:46:35 by iiliuk            #+#    #+#             */
/*   Updated: 2016/07/27 22:40:15 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *current;
	t_list *tmp;

	prev = 0;
	current = *begin_list;
	while (current)
	{
		tmp = current->next;
		current->next = prev;
		prev = current;
		current = tmp;
	}
	*begin_list = prev;
}
