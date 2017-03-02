/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_digit_oux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:42 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:42 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	get_unsigned_arg(t_flags *got_flags, va_list *args)
{
	if (got_flags->len_mod == hh)
		return (unsigned long long)(unsigned char)va_arg(*args, unsigned int);
	if (got_flags->len_mod == h)
		return (unsigned long long)(unsigned short int)
		va_arg(*args, unsigned int);
	if (got_flags->len_mod == none)
		return (unsigned long long)va_arg(*args, unsigned int);
	if (got_flags->len_mod == l)
		return (unsigned long long)va_arg(*args, unsigned long);
	if (got_flags->len_mod == ll)
		return (unsigned long long)va_arg(*args, unsigned long long);
	if (got_flags->len_mod == j)
		return (unsigned long long)va_arg(*args, uintmax_t);
	if (got_flags->len_mod == z)
		return (unsigned long long)va_arg(*args, size_t);
	if (got_flags->len_mod == t)
		return (unsigned long long)va_arg(*args, unsigned long long);
	return (0);
}

int							process_o(t_flags *got_flags, va_list *args)
{
	char				*str;
	unsigned long long	arg;

	arg = get_unsigned_arg(got_flags, args);
	str = ft_itoa_unbase(arg, 8);
	if (!got_flags->pound)
	{
		if (!arg && !got_flags->precision)
			return (process_width_i(0, got_flags));
	}
	else
	{
		str = ft_strjoin("0", str);
		if (!arg && (!got_flags->got_precis ||
		(got_flags->got_precis && !got_flags->precision)))
			return (write(1, "0", 1));
	}
	got_flags->length = ft_strlen(str);
	process_precision_i(&str, got_flags);
	process_width_s(&str, got_flags);
	ft_putstr(str);
	return (ft_strlen(str));
}

int							process_u(t_flags *got_flags, va_list *args)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = get_unsigned_arg(got_flags, args);
	str = ft_itoa_unbase(arg, 10);
	if (got_flags->precision == 0 && arg == 0)
		return (0);
	got_flags->length = ft_strlen(str);
	process_precision_i(&str, got_flags);
	process_width_s(&str, got_flags);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	str = NULL;
	return (len);
}

static int					process_x_not_null(t_flags *got_flags, char *str)
{
	got_flags->length = ft_strlen(str);
	process_precision_i(&str, got_flags);
	if (got_flags->pad_zero && got_flags->pound)
	{
		got_flags->width -= 2;
		process_width_s(&str, got_flags);
	}
	if (ft_strcmp("0", str) && got_flags->pound)
		str = ft_strjoin("0X", str);
	process_width_s(&str, got_flags);
	if (got_flags->conv_spec == 'X')
		ft_putstr(str);
	else
		ft_putstr_tolower(str);
	return (ft_strlen(str));
}

int							process_x(t_flags *got_flags, va_list *args)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = get_unsigned_arg(got_flags, args);
	if (arg)
	{
		str = ft_itoa_unbase(arg, 16);
		return (process_x_not_null(got_flags, str));
	}
	else
	{
		str = ft_strnew(1);
		if (got_flags->got_precis && got_flags->precision == 0)
			str[0] = 0;
		else
			str = ft_strjoin("0", str);
		process_precision_i(&str, got_flags);
		process_width_s(&str, got_flags);
		ft_putstr(str);
	}
	len = ft_strlen(str);
	free(str);
	str = NULL;
	return (len);
}
