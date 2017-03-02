/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:20:38 by iiliuk            #+#    #+#             */
/*   Updated: 2017/02/01 16:20:38 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include "libft.h"

enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t
}					len_mod;

typedef struct		s_flags
{
	int				pound;
	int				pad_zero;
	int				left_justify;
	int				space;
	int				sign;
	int				got_width;
	int				got_precis;
	int				width;
	unsigned int	precision;
	unsigned int	length;
	char			len_mod;
	char			conv_spec;
}					t_flags;

int					ft_printf(char *fmt, ...);
int					get_flags(char *fmt, va_list *args);
int					process_non_valid(t_flags *got_flags);

int					process_c_s(t_flags *got_flags, va_list *args);
size_t				ft_wstrlen(wchar_t *str);
int					ft_wcharlen(wchar_t c);
void				wchar_to_str(wchar_t wchar, char *str);
int					process_wide_str(t_flags *got_flags, va_list *args);
int					process_width_ws(wchar_t **wstr, t_flags *got_flags);
void				process_precision_ws(wchar_t **wstr, t_flags *got_flags);

int					process_digit(t_flags *got_flags, va_list *args);
int					process_o(t_flags *got_flags, va_list *args);
int					process_u(t_flags *got_flags, va_list *args);
int					process_x(t_flags *got_flags, va_list *args);

int					process_ptr(t_flags *got_flags, va_list *args);

int					process_percent(t_flags *got_flags, va_list *args);

int					process_width_i(unsigned int i, t_flags *got_flags);
void				process_width_s(char **str, t_flags *got_flags);
void				process_precision_i(char **str, t_flags *got_flags);
void				process_precision_s(char **str, t_flags *got_flags);

int					ft_strlen_num(unsigned int x);
void				ft_putstr_tolower(char *s);
int					isnot_percent(int c);

#endif
