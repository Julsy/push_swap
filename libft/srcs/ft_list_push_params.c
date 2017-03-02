/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 10:34:05 by iiliuk            #+#    #+#             */
/*   Updated: 2016/07/27 21:10:46 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;

	i = 2;
	if (ac == 1)
		return (0);
	list = ft_lstnew(av[i], sizeof(char));
	list->next = 0;
	while (i < ac)
	{
		tmp = list;
		list = ft_lstnew(av[i], sizeof(char));
		list->next = tmp;
		i++;
	}
	return (list);
}
