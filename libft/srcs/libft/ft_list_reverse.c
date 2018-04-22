/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:36:48 by hlely             #+#    #+#             */
/*   Updated: 2017/11/25 21:13:30 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *next;
	t_list *new;
	t_list *cur;

	if ((*begin_list) != NULL && (*begin_list)->next != NULL)
	{
		cur = (*begin_list)->next;
		next = cur;
		new = (*begin_list);
		new->next = NULL;
		while (next != NULL)
		{
			next = cur->next;
			cur->next = new;
			new = cur;
			if (next != NULL)
				cur = next;
		}
		*begin_list = cur;
	}
}
