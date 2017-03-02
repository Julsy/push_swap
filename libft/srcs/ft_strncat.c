/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:35:18 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/22 16:57:04 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	len;
	int				i;

	i = 0;
	len = 0;
	while (s1[i])
		i++;
	while (s1 && s2[len] != '\0' && len < n)
	{
		s1[i] = s2[len];
		i++;
		len++;
	}
	s1[i] = '\0';
	return (s1);
}
