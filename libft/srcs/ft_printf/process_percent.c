/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:28:46 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 17:28:46 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_percent(t_flags *got_flags, va_list *args)
{
	char	*str;
	int		len;

	len = 0;
	(void)args;
	str = ft_strnew(1);
	str[0] = '%';
	process_width_s(&str, got_flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
