/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:41:22 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/26 17:41:22 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	i = 0;
	if (s && f)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (new_str)
		{
			while (s[i] != 0)
			{
				new_str[i] = f(i, s[i]);
				i++;
			}
			return (new_str);
		}
	}
	return (NULL);
}
