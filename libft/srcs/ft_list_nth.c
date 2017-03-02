/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 17:38:09 by iiliuk            #+#    #+#             */
/*   Updated: 2016/07/27 21:38:32 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_nth(t_list *begin_list, unsigned int nbr)
{
	t_list	*list;

	list = begin_list;
	while (nbr > 1)
	{
		if (!list)
			return (NULL);
		list = list->next;
		nbr--;
	}
	return (list);
}
