/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:57:46 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:35 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

typedef struct		s_lst
{
	void			*left;
	size_t			left_size;
	struct s_lst	*next;
	int				fd;
}					t_lst;

int					get_next_line(int const fd, char **line);
int					check_extra(int fd, char *buf, t_lst **head);
t_lst				*find_extra(int fd, t_lst **head);
char				*get_extra_else(t_lst *elem);
char				*get_extra(int fd, t_lst **head);

#endif
