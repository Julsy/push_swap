/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:25:23 by iiliuk            #+#    #+#             */
/*   Updated: 2017/01/11 15:25:23 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_format(char *fmt, va_list *args, int *chars_printed)
{
	char		*format;
	char		*tmp;
	int			len;
	const char	spec_type[15] = "sSpdDioOuUxXcC%";
	const char	possible_type[19] = "sSpdDioOuUxXcC%hljz";

	len = 0;
	tmp = fmt;
	format = NULL;
	while (tmp[len] != '\0')
	{
		if (ft_strchr(spec_type, tmp[len]) != NULL ||
		(ft_isalpha(tmp[len]) != 0 && !ft_strchr(possible_type, tmp[len])))
		{
			format = ft_strndup(fmt, ++len);
			break ;
		}
		len++;
	}
	if (format == NULL)
		return (0);
	*chars_printed += get_flags(format, args);
	return (len);
}

static int		my_printf(char *fmt, va_list *args, int *chars_printed)
{
	int *ptr;

	ptr = 0;
	while (*fmt)
	{
		if (isnot_percent(*fmt) == 1)
		{
			*chars_printed += write(1, fmt, 1);
			fmt++;
		}
		else
		{
			fmt++;
			if (*fmt == 'n')
			{
				ptr = va_arg(*args, int*);
				*ptr = *chars_printed;
				fmt++;
				continue ;
			}
			fmt += get_format(fmt, args, chars_printed);
		}
	}
	return (*chars_printed);
}

int				ft_printf(char *fmt, ...)
{
	va_list		args;
	static int	chars_printed;

	chars_printed = 0;
	va_start(args, fmt);
	chars_printed = my_printf(fmt, &args, &chars_printed);
	va_end(args);
	return (chars_printed);
}

int				process_non_valid(t_flags *got_flags)
{
	char	*str;

	str = ft_strnew(1);
	if (got_flags->left_justify || got_flags->space ||
	!got_flags->got_width || !got_flags->got_precis)
	{
		str[0] = got_flags->conv_spec;
		process_width_s(&str, got_flags);
	}
	else
	{
		process_width_s(&str, got_flags);
		str[ft_strlen(str) - 1] = got_flags->conv_spec;
	}
	ft_putstr(str);
	free(str);
	str = NULL;
	return (got_flags->width);
}
