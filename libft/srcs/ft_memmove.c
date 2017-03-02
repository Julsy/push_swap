/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:53:23 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/23 15:53:23 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void *tmp;

	tmp = ft_memalloc(n);
	if (tmp != NULL)
	{
		tmp = ft_memcpy(tmp, src, n);
		dest = ft_memcpy(dest, tmp, n);
		free(tmp);
	}
	return (dest);
}
