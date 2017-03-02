/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:16:16 by iiliuk            #+#    #+#             */
/*   Updated: 2016/09/27 13:16:16 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		len;
	size_t		begin;

	begin = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len > 0)
		len--;
	if (s[begin] == '\0')
		return (ft_strnew(0));
	str = ft_strsub(s, begin, len - begin + 1);
	return (str);
}
