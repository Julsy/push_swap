/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:01:24 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/01 18:53:10 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litl, size_t len)
{
	size_t	i;

	if (*litl == '\0')
		return ((char *)big);
	i = ft_strlen(litl);
	while (*big != '\0' && len >= i)
	{
		if (ft_strncmp(big, litl, i) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
