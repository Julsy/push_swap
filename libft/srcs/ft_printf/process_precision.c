/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:50 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:50 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_precision_s(char **str, t_flags *got_flags)
{
	if (got_flags->got_precis == 0)
		return ;
	if (got_flags->length <= got_flags->precision)
		return ;
	*str = ft_strndup(*str, got_flags->precision);
}

void	process_precision_ws(wchar_t **wstr, t_flags *got_flags)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	if (got_flags->got_precis == 0)
		return ;
	if (ft_wstrlen(*wstr) <= got_flags->precision)
		return ;
	while ((*wstr)[i] && len <= got_flags->precision)
		len += ft_wcharlen((*wstr)[i++]);
	(*wstr)[i - 1] = 0;
}

void	process_precision_i(char **str, t_flags *got_flags)
{
	char	*tmp;

	if (got_flags->got_precis == 0)
		return ;
	if (got_flags->length > got_flags->precision)
		return ;
	got_flags->pad_zero = 0;
	tmp = ft_strnew(got_flags->precision);
	if (*str[0] == '-')
	{
		ft_memset(tmp, '0', got_flags->precision - (ft_strlen(*str) - 1));
		tmp = ft_strjoin("-", tmp);
		*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		tmp = ft_strjoin(tmp, *str);
	}
	else
	{
		ft_memset(tmp, '0', got_flags->precision - got_flags->length);
		ft_strcpy(tmp + got_flags->precision - ft_strlen(*str), *str);
	}
	free(*str);
	*str = NULL;
	*str = tmp;
}
