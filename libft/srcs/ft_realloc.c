/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:50:08 by iiliuk            #+#    #+#             */
/*   Updated: 2016/11/22 16:50:15 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
