/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:57:49 by iiliuk            #+#    #+#             */
/*   Updated: 2016/12/01 19:59:20 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				bytes_read;
	int				res;
	static t_lst	*head;

	while ((bytes_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (bytes_read < 0 || fd < 0 || line == NULL)
			return (-1);
		buf[bytes_read] = '\0';
		if ((res = check_extra(fd, buf, &head)) == 1)
		{
			*line = get_extra(fd, &head);
			return (1);
		}
		if (res == -1)
			return (-1);
	}
	if ((*line = get_extra(fd, &head)) != NULL)
		return (1);
	return (0);
}

char	*get_extra(int fd, t_lst **head)
{
	t_lst	*elem;
	char	*begin;
	char	*end;
	char	*tmp;

	elem = find_extra(fd, head);
	if (elem->left == NULL)
		return (NULL);
	if ((end = ft_strstr((char *)elem->left, "\n")) != NULL)
	{
		if (!(begin = ft_strsub((char *)elem->left, 0,
						(elem->left_size - ft_strlen(++end) - 2))))
			return (NULL);
		tmp = elem->left;
		elem->left = (ft_strlen(end) == 0) ? NULL : (void *)ft_strdup(end);
		elem->left_size = ft_strlen(end) + 1;
		free(tmp);
	}
	else
	{
		begin = get_extra_else(elem);
		if (!begin)
			return (NULL);
	}
	return (begin);
}

char	*get_extra_else(t_lst *elem)
{
	char *begin;

	if (!(begin = ft_strdup((char *)elem->left)))
		return (NULL);
	free((*elem).left);
	elem->left = NULL;
	elem->left_size = 0;
	return (begin);
}

t_lst	*find_extra(int fd, t_lst **head)
{
	t_lst	*tmp;

	tmp = *head;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	return (tmp);
}

int		check_extra(int fd, char *buf, t_lst **head)
{
	t_lst	*elem;
	char	*tmp;

	elem = find_extra(fd, head);
	if (elem == NULL)
	{
		if (!(elem = (t_lst *)ft_lstnew((void *)buf, (ft_strlen(buf) + 1))))
			return (-1);
		elem->fd = fd;
		ft_list_add_back((t_list **)head, (t_list *)elem);
	}
	else
	{
		if (!(tmp = ft_strjoin((char *)elem->left, buf)))
			return (-1);
		free(elem->left);
		elem->left = (void *)tmp;
		elem->left_size = ft_strlen(tmp) + 1;
	}
	if (ft_strstr((char *)elem->left, "\n") != NULL)
		return (1);
	return (0);
}
