/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:33 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:33 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_str(t_flags *got_flags, va_list *args)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(*args, char*);
	if (str == NULL)
	{
		if (got_flags->got_precis == 0 ||
		(got_flags->got_precis && got_flags->precision))
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
	}
	str = ft_strdup(str);
	got_flags->length = ft_strlen(str);
	process_precision_s(&str, got_flags);
	process_width_s(&str, got_flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

static int	process_char(t_flags *got_flags, va_list *args)
{
	char	*str;
	int		len;
	int		flag;
	int		c;

	len = 0;
	flag = 0;
	c = va_arg(*args, int);
	str = ft_strnew(1);
	if (got_flags->left_justify && !c)
		len += write(1, "\0", 1);
	if (c == 0)
		flag = 1;
	else
		str[0] = c;
	got_flags->width -= got_flags->width > 0 ? flag : 0;
	process_width_s(&str, got_flags);
	len += ft_strlen(str);
	ft_putstr(str);
	if (flag == 1 && !got_flags->left_justify)
		len += write(1, "\0", 1);
	free(str);
	str = NULL;
	return (len);
}

static int	process_wide_char(t_flags *got_flags, va_list *args)
{
	int		len;
	char	*str;
	wchar_t	wchar;

	len = 0;
	wchar = va_arg(*args, wchar_t);
	len = ft_wcharlen(wchar);
	str = ft_strnew(len);
	if (wchar == 0)
		write(1, "\0", 1);
	wchar_to_str(wchar, str);
	process_width_s(&str, got_flags);
	ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

int			process_c_s(t_flags *got_flags, va_list *args)
{
	int	len;

	len = 0;
	if (got_flags->conv_spec == 's' || got_flags->conv_spec == 'S')
	{
		if (got_flags->len_mod == l || got_flags->conv_spec == 'S')
			len = process_wide_str(got_flags, args);
		else
			len = process_str(got_flags, args);
	}
	else if (got_flags->conv_spec == 'c' || got_flags->conv_spec == 'C')
	{
		if (got_flags->len_mod == l || got_flags->conv_spec == 'C')
			len = process_wide_char(got_flags, args);
		else
			len = process_char(got_flags, args);
	}
	return (len);
}
