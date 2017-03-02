/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:09 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:09 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_tolower(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] <= 90 && s[i] >= 65)
			s[i] = s[i] + 32;
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_strlen_num(unsigned int x)
{
	if (x < 10)
		return (1);
	else
		return (ft_strlen_num(x / 10) + 1);
}

int		isnot_percent(int c)
{
	if (c >= 0000 && c <= 0177 && c != 37)
		return (1);
	return (0);
}

int		ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
