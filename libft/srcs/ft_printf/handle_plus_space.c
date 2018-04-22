/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plus_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:55:38 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 10:18:22 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	first_sign(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (str[i]);
		i++;
	}
	return (0);
}

char	*analyse_src(char *src, char *tmp)
{
	if (first_sign(src) == '-')
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("");
		return (tmp);
	}
	return (tmp);
}

char	*handle_plus_space(char *src, t_opt *opt, int type)
{
	char	*tmp;

	if (type == INT)
	{
		if ((opt->flags & PLUS) && type == 1)
		{
			tmp = (opt->positive) ? ft_strdup("+") : ft_strdup("-");
			tmp = analyse_src(src, tmp);
			tmp = ft_strjoinddel(tmp, src);
			return (tmp);
		}
		else if (opt->flags & SPACE)
		{
			tmp = (opt->positive) ? ft_strdup(" ") : ft_strdup("-");
			tmp = analyse_src(src, tmp);
			tmp = ft_strjoinddel(tmp, src);
			return (tmp);
		}
	}
	return (src);
}
