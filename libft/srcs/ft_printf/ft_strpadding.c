/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:42:51 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:48:52 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_preci(char *src, int preci)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_strnew(ft_strlen(src));
	while (src[i] && i < preci)
	{
		dest = ft_strncat(dest, src + i, 1);
		i++;
	}
	ft_strdel(&src);
	return (dest);
}

static char	*handle_width(char *src, t_opt opt)
{
	int		len;
	char	*tmp;

	len = opt.width - ft_strlen(src);
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = (opt.zero && (opt.flags & MINUS) == 0) ?
			ft_strjoindel(tmp, "0") : ft_strjoindel(tmp, " ");
		len--;
	}
	if (opt.flags & MINUS)
		tmp = ft_strjoinddel(src, tmp);
	else
	{
		tmp = ft_strjoindel(tmp, src);
		ft_strdel(&src);
	}
	return (tmp);
}

char		*handle_strflag(char *src, t_opt opt)
{
	if (opt.preci != -1)
		src = handle_preci(src, opt.preci);
	src = handle_width(src, opt);
	return (src);
}
