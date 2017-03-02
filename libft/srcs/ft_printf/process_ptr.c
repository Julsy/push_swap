/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:53 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:53 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_null(t_flags *got_flags, char **ptr)
{
	process_precision_i(ptr, got_flags);
	if (got_flags->pad_zero)
	{
		got_flags->width -= 2;
		process_width_s(ptr, got_flags);
	}
	if (got_flags->precision == 0 && got_flags->got_precis)
		*ptr = ft_strdup("");
	*ptr = ft_strjoin("0x", *ptr);
	if (!got_flags->pad_zero)
		process_width_s(ptr, got_flags);
	return (ft_strlen(*ptr));
}

static int	pointer(t_flags *got_flags, char **ptr)
{
	process_precision_i(ptr, got_flags);
	if (got_flags->pound && got_flags->got_precis)
		got_flags->pad_zero = 0;
	*ptr = ft_strjoin("0x", *ptr);
	process_width_s(ptr, got_flags);
	return (ft_strlen(*ptr));
}

int			process_ptr(t_flags *got_flags, va_list *args)
{
	char	*ptr;
	int		len;

	len = 0;
	ptr = va_arg(*args, void*);
	ptr = ft_itoa_unbase((unsigned long long)ptr, 16);
	got_flags->length = ft_strlen(ptr);
	if (!ft_strcmp(ptr, "0"))
		len = ptr_null(got_flags, &ptr);
	else
		len = pointer(got_flags, &ptr);
	ft_putstr_tolower(ptr);
	free(ptr);
	ptr = NULL;
	return (len);
}
