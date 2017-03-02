/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:41:54 by iiliuk            #+#    #+#             */
/*   Updated: 2016/12/01 15:30:15 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;
	void	*cpy;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	elem->next = NULL;
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(cpy = malloc(content_size)))
		{
			free(elem);
			return (NULL);
		}
		elem->content = ft_memcpy(cpy, content, content_size);
		elem->content_size = content_size;
	}
	return (elem);
}
