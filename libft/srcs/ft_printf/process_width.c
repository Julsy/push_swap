/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:29:02 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/27 14:53:17 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*right_justify(char **str, t_flags *got_flags, char *tmp)
{
	if (got_flags->pad_zero == 1)
	{
		if (*str[0] == '-' || got_flags->space)
		{
			ft_memset(tmp, '0', got_flags->width - ft_strlen(*str) + 1);
			tmp[0] = got_flags->space ? ' ' : '-';
			*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
			tmp = ft_strjoin(tmp, *str);
		}
		else
			ft_memset(tmp, '0', got_flags->width - ft_strlen(*str));
	}
	else
		ft_memset(tmp, ' ', got_flags->width - ft_strlen(*str));
	ft_strcpy(tmp + got_flags->width - ft_strlen(*str), *str);
	return (tmp);
}

void		process_width_s(char **str, t_flags *got_flags)
{
	int		len;
	char	*tmp;

	len = 0;
	if (got_flags->got_width == 0)
		return ;
	if ((unsigned int)got_flags->width <= ft_strlen(*str))
		return ;
	tmp = ft_strnew(got_flags->width);
	if (got_flags->left_justify == 1)
	{
		ft_strcpy(tmp, *str);
		ft_memset(tmp + ft_strlen(*str), ' ',
		got_flags->width - ft_strlen(*str));
	}
	else
		tmp = right_justify(str, got_flags, tmp);
	*str = tmp;
}

int			process_width_i(unsigned int i, t_flags *got_flags)
{
	int		len;
	char	*tmp;

	len = 0;
	if (got_flags->got_width == 0)
		return (0);
	tmp = ft_strnew(got_flags->width);
	if (got_flags->width < 0)
		ft_memset(tmp, ' ', i);
	else
		ft_memset(tmp, ' ', got_flags->width - i);
	len = ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = NULL;
	return (len);
}
