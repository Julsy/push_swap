/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_wide_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:58 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:58 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_wstrdup(wchar_t *str)
{
	wchar_t	*res;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	res = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(str) + 1));
	while (i < ft_wstrlen(str))
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

void			wchar_to_str(wchar_t wchar, char *str)
{
	if (wchar <= 0x7F)
		str[0] = wchar;
	else if (wchar <= 0x7FF)
	{
		str[0] = 192 | (((unsigned int)(wchar) >> 6) & 63);
		str[1] = 128 | ((unsigned int)(wchar) & 63);
	}
	else if (wchar <= 0xFFFF)
	{
		str[0] = 224 | (((unsigned int)(wchar) >> 12) & 63);
		str[1] = 128 | (((unsigned int)(wchar) >> 6) & 63);
		str[2] = 128 | ((unsigned int)(wchar) & 63);
	}
	else if (wchar <= 0x10FFFF)
	{
		str[0] = 240 | (((unsigned int)(wchar) >> 18) & 63);
		str[1] = 128 | (((unsigned int)(wchar) >> 12) & 63);
		str[2] = 128 | (((unsigned int)(wchar) >> 6) & 63);
		str[3] = 128 | ((unsigned int)(wchar) & 63);
	}
}

static char		*wchars_to_str(wchar_t *wstr)
{
	size_t	len;
	char	*res;
	int		i;

	len = ft_wstrlen(wstr);
	res = ft_strnew(len);
	i = 0;
	while (*wstr)
	{
		wchar_to_str(*wstr, res + i);
		i += ft_wcharlen(*wstr);
		wstr++;
	}
	return (res);
}

static int		process_wide_str_null(t_flags *got_flags)
{
	int		len;
	char	*str;

	len = 0;
	str = NULL;
	if (!got_flags->got_precis ||
		(got_flags->got_precis && got_flags->precision >= 6))
		str = ft_strdup("(null)");
	else
		str = ft_strdup("");
	process_width_s(&str, got_flags);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	str = NULL;
	return (len);
}

int				process_wide_str(t_flags *got_flags, va_list *args)
{
	wchar_t	*wstr;
	char	*str;
	int		len;

	len = 0;
	wstr = ft_wstrdup(va_arg(*args, wchar_t*));
	if (wstr == NULL)
		return (process_wide_str_null(got_flags));
	else
	{
		process_precision_ws(&wstr, got_flags);
		str = wchars_to_str(wstr);
		process_width_s(&str, got_flags);
		if (got_flags->got_width)
			len = ((unsigned int)got_flags->width >
			ft_wstrlen(wstr)) ? got_flags->width : ft_wstrlen(wstr);
		else
			len = ft_wstrlen(wstr);
	}
	ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}
