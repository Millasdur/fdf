/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:44:45 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 17:26:39 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setres(char const *s, int var[2], t_list **res)
{
	int		end;
	t_list	*tmp;

	end = 0;
	while (s[(var)[0]] && s[(var[0])] == var[1])
		(var[0])++;
	end = var[0];
	while (s[end] && s[end] != var[1])
		end++;
	if (end - var[0] != 0)
	{
		tmp = ft_lstnew(ft_strsub(s, var[0], end - var[0]), end - var[0]);
		ft_lstaddlast(res, tmp);
	}
	var[0] = end;
}

t_list		*ft_strsplitlist(char const *s, char c)
{
	int				var[2];
	t_list			**res;
	t_list			*tmp;

	var[0] = 0;
	var[1] = c;
	res = NULL;
	if (s && c)
	{
		while (s[var[0]])
			setres(s, var, res);
		tmp = ft_lstnew(ft_strnew(1), 2);
		ft_lstaddlast(res, tmp);
		return (*res);
	}
	return (0);
}
