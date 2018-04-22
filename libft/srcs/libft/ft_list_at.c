/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:50:01 by hlely             #+#    #+#             */
/*   Updated: 2017/11/28 15:51:50 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int j;

	j = 0;
	while (begin_list != NULL && j != nbr)
	{
		begin_list = begin_list->next;
		j++;
	}
	if (j != nbr)
		return (NULL);
	return (begin_list);
}
