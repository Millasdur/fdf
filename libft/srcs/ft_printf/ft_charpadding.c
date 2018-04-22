/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpadding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:43:23 by hlely             #+#    #+#             */
/*   Updated: 2018/04/21 17:13:28 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_width(char *src, t_opt opt, int zero)
{
	int		len;
	char	*tmp;

	len = opt.width - ft_strlen(src) - zero;
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = (opt.zero && (opt.flags & MINUS) == 0) ?
			ft_strjoindel(tmp, "0") : ft_strjoindel(tmp, " ");
		len--;
	}
	if (opt.flags & MINUS)
		tmp = ft_strnjoinddel(src, tmp, 1, ft_strlen(tmp));
	else
	{
		tmp = ft_strnjoindel(tmp, src, ft_strlen(tmp), 1);
		ft_strdel(&src);
	}
	return (tmp);
}

char		*handle_charflag(char *src, t_opt opt, int len)
{
	src = handle_width(src, opt, len);
	return (src);
}
