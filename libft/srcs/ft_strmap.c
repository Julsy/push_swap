/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:27:54 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/26 16:27:54 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	if (!s || !f)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s));
	if (new_str != NULL)
	{
		i = 0;
		while (*s)
		{
			new_str[i++] = f(*s);
			s++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
