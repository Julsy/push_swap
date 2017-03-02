/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:22:58 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/23 10:43:21 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;

	if (len == 0)
		return (b);
	bytes = (unsigned char *)b;
	while (len > 0)
	{
		*bytes = (unsigned char)c;
		bytes++;
		len--;
	}
	return (b);
}
