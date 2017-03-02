/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_digit_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:37 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:37 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ptrdiff_t	get_signed_arg(t_flags *got_flags, va_list *args)
{
	if (got_flags->len_mod == hh)
		return (ptrdiff_t)(signed char)va_arg(*args, int);
	if (got_flags->len_mod == h)
		return (ptrdiff_t)(short int)va_arg(*args, int);
	if (got_flags->len_mod == none)
		return (ptrdiff_t)va_arg(*args, int);
	if (got_flags->len_mod == l)
		return (ptrdiff_t)va_arg(*args, long);
	if (got_flags->len_mod == ll)
		return (ptrdiff_t)va_arg(*args, long long);
	if (got_flags->len_mod == j)
		return (ptrdiff_t)va_arg(*args, intmax_t);
	if (got_flags->len_mod == z)
		return (ptrdiff_t)va_arg(*args, ssize_t);
	if (got_flags->len_mod == t)
		return (ptrdiff_t)va_arg(*args, ptrdiff_t);
	return (0);
}

static int			process_signed(t_flags *got_flags, va_list *args)
{
	char		*str;
	ptrdiff_t	sarg;

	sarg = get_signed_arg(got_flags, args);
	if (got_flags->precision == 0 && !sarg)
		return (process_width_i(0, got_flags));
	str = ft_itoa(sarg);
	got_flags->length = ft_strlen(str);
	if (got_flags->pad_zero &&
	!got_flags->got_precis && !got_flags->left_justify &&
	got_flags->length < (unsigned int)got_flags->width)
	{
		got_flags->got_precis = 1;
		got_flags->precision = (got_flags->sign || sarg < 0 ||
		got_flags->space) ? got_flags->width - 1 : got_flags->width;
	}
	process_precision_i(&str, got_flags);
	if (got_flags->space && str[0] != '-' && !got_flags->sign)
		str = ft_strjoin(" ", str);
	if (got_flags->sign && sarg >= 0)
		str = ft_strjoin("+", str);
	process_width_s(&str, got_flags);
	ft_putstr(str);
	return (ft_strlen(str));
}

static int			process_unsigned(t_flags *got_flags, va_list *args)
{
	int		len;

	len = 0;
	if (got_flags->conv_spec == 'o' || got_flags->conv_spec == 'O')
	{
		if (got_flags->conv_spec == 'O')
		{
			got_flags->conv_spec = 'o';
			got_flags->len_mod = l;
		}
		len = process_o(got_flags, args);
	}
	else if (got_flags->conv_spec == 'u' || got_flags->conv_spec == 'U')
	{
		if (got_flags->conv_spec == 'U')
		{
			got_flags->conv_spec = 'u';
			got_flags->len_mod = l;
		}
		len = process_u(got_flags, args);
	}
	else if (got_flags->conv_spec == 'x' || got_flags->conv_spec == 'X')
		len = process_x(got_flags, args);
	return (len);
}

int					process_digit(t_flags *got_flags, va_list *args)
{
	int	len;

	len = 0;
	if (got_flags->conv_spec == 'd' || got_flags->conv_spec == 'D'
	|| got_flags->conv_spec == 'i')
	{
		if (got_flags->conv_spec == 'D')
		{
			got_flags->conv_spec = 'd';
			got_flags->len_mod = l;
		}
		len = process_signed(got_flags, args);
	}
	else
		len = process_unsigned(got_flags, args);
	return (len);
}
