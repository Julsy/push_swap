/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:59:22 by iiliuk            #+#    #+#             */
/*   Updated: 2017/01/23 14:59:22 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unbase(unsigned long long nb, unsigned int base)
{
	char				*str;
	int					length;
	unsigned long long	value;
	const char			base_str[16] = "0123456789ABCDEF";

	value = nb;
	length = 1;
	while (value >= base)
	{
		length++;
		value = value / base;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	while (0 < length--)
	{
		str[length] = base_str[nb % base];
		nb = nb / base;
	}
	return (str);
}
