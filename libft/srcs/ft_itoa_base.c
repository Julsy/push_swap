/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:13:56 by iiliuk            #+#    #+#             */
/*   Updated: 2016/12/14 18:14:19 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ptrdiff_t	cnvt_nbr(ptrdiff_t value, int base, ptrdiff_t *store)
{
	int			i;
	ptrdiff_t	val;

	i = 0;
	val = value;
	while (value)
	{
		store[i] = ft_abs(value % base);
		value /= base;
		i++;
	}
	if (base == 10 && val < 0)
	{
		store[i] = '-';
		i++;
	}
	return (i);
}

char		*ft_itoa_base(ptrdiff_t value, int base)
{
	const char	*base_digits = "0123456789ABCDEF";
	ptrdiff_t	store[32];
	int			i;
	int			j;
	char		*res;

	i = 0;
	j = 0;
	if (base < 2 || base > 16 || value == 0)
		return (ft_strdup("0"));
	j = cnvt_nbr(value, base, store);
	res = malloc(j + 1);
	res[j] = '\0';
	while (j--)
	{
		if (store[i] == '-')
			res[j] = store[i];
		else
			res[j] = base_digits[store[i]];
		i++;
	}
	return (res);
}
