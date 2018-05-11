/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:26:20 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 19:07:25 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	void	*dest;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		dest = (void*)malloc(content_size);
		dest = ft_memcpy(dest, content, content_size);
		res->content = dest;
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
