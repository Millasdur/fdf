/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:30:48 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 16:35:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	first_number(char *str)
{
	int		i;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '0')
		return (1);
	return (0);
}

char		*calc_tmp(char *src, t_opt *opt, int type)
{
	if (type == OCT &&
			((int)ft_strlen(src) >= opt->preci && !first_number(src)))
	{
		opt->flags &= ~HASH;
		return (ft_strjoin("0", src));
	}
	else if (type == HEX || type == POINT)
	{
		opt->flags &= ~HASH;
		return (ft_strjoin("0x", src));
	}
	else if (type == MHEX)
	{
		opt->flags &= ~HASH;
		return (ft_strjoin("0X", src));
	}
	else
		return (ft_strdup(src));
}

char		*handle_hash(char *src, t_opt *opt, int type)
{
	char	*tmp;

	if (opt->flags & HASH)
	{
		tmp = calc_tmp(src, opt, type);
		tmp = handle_plus_space(tmp, opt, type);
		opt->flags &= ~PLUS;
		opt->flags &= ~SPACE;
		ft_strdel(&src);
		return (tmp);
	}
	src = handle_plus_space(src, opt, type);
	opt->flags &= ~PLUS;
	opt->flags &= ~SPACE;
	return (src);
}
