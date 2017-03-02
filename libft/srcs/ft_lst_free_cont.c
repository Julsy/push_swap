/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:21:31 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/01 15:15:09 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free_cont(void *cont, size_t cont_size)
{
	(void)cont_size;
	ft_bzero(cont, cont_size);
	free(cont);
}
