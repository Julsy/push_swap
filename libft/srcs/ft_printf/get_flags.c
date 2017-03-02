/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:25 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/27 14:53:09 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_width_precision(char *fmt, t_flags *got_flags)
{
	int i;

	i = 0;
	got_flags->width = 1;
	got_flags->precision = 1;
	got_flags->got_precis = 0;
	got_flags->got_width = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '.' && fmt[i] != '0' && ft_isdigit(fmt[i]))
		{
			got_flags->got_width = 1;
			got_flags->width = ft_atoi(fmt + i);
			while (fmt[i] && ft_isdigit(fmt[i]))
				i++;
		}
		if (fmt[i] == '.' && fmt[i + 1] != '*')
		{
			got_flags->got_precis = 1;
			got_flags->precision = ft_atoi(fmt + i + 1);
			while (fmt[i] && ft_isdigit(fmt[i + 1]))
				i++;
		}
		i++;
	}
}

static void		get_star(char *fmt, t_flags *got_flags, va_list *args)
{
	int i;
	int arg;

	i = -1;
	while (fmt[++i] != '\0')
	{
		if (fmt[i] == '*' && !ft_isdigit(fmt[i + 1]))
		{
			arg = va_arg(*args, int);
			if (fmt[i - 1] == '.')
			{
				got_flags->got_precis = (arg >= 0) ? 1 : 0;
				got_flags->precision = (arg >= 0) ? arg : 0;
			}
			else
			{
				got_flags->left_justify = (got_flags->left_justify ||
				arg < 0) ? 1 : 0;
				got_flags->got_width = 1;
				got_flags->width = ft_abs(arg);
			}
		}
		else if (fmt[i] == '*')
			arg = va_arg(*args, int);
	}
}

static void		get_len_mod(char *fmt, t_flags *got_flags)
{
	int	i;

	i = -1;
	while (fmt[++i] != '\0')
	{
		if (fmt[i] == 'h')
			got_flags->len_mod = (fmt[++i] == 'h') ? hh : h;
		else if (fmt[i] == 'l')
		{
			if (fmt[++i] == 'l')
				got_flags->len_mod = ll;
			else
				got_flags->len_mod = l;
		}
		else if (fmt[i] == 'j')
			got_flags->len_mod = j;
		else if (fmt[i] == 'z')
			got_flags->len_mod = z;
		else if (fmt[i] == 't')
			got_flags->len_mod = t;
		i++;
	}
}

static int		process_conv(t_flags *got_flags, va_list *args)
{
	if (got_flags->conv_spec == 's' || got_flags->conv_spec == 'S' ||
	got_flags->conv_spec == 'c' || got_flags->conv_spec == 'C')
		return (process_c_s(got_flags, args));
	else if (got_flags->conv_spec == 'd' || got_flags->conv_spec == 'D' ||
	got_flags->conv_spec == 'i' || got_flags->conv_spec == 'o' ||
	got_flags->conv_spec == 'O' || got_flags->conv_spec == 'u' ||
	got_flags->conv_spec == 'U' || got_flags->conv_spec == 'x' ||
	got_flags->conv_spec == 'X')
		return (process_digit(got_flags, args));
	else if (got_flags->conv_spec == 'p')
		return (process_ptr(got_flags, args));
	else if (got_flags->conv_spec == '%')
		return (process_percent(got_flags, args));
	else
		return (process_non_valid(got_flags));
}

int				get_flags(char *fmt, va_list *args)
{
	int			i;
	t_flags		*got_flags;

	i = 0;
	got_flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	got_flags->conv_spec = fmt[ft_strlen(fmt) - 1];
	while (fmt[i] != '\0')
	{
		got_flags->pound = (fmt[i] == '#') ? 1 : got_flags->pound;
		got_flags->sign = (fmt[i] == '+') ? 1 : got_flags->sign;
		if (fmt[i] == '0' && fmt[i - 1] != '.' && !ft_isdigit(fmt[i - 1]))
			got_flags->pad_zero = 1;
		if (fmt[i] == '-')
			got_flags->left_justify = 1;
		if (fmt[i] == ' ')
			got_flags->space = 1;
		i++;
	}
	get_width_precision(fmt, got_flags);
	get_star(fmt, got_flags, args);
	get_len_mod(fmt, got_flags);
	i = process_conv(got_flags, args);
	free(got_flags);
	return (i);
}
