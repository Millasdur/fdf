/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:33:54 by hlely             #+#    #+#             */
/*   Updated: 2018/04/21 16:11:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_preci(char *src, int preci)
{
	int		len;
	char	*tmp;

	len = preci - ft_strlen(src);
	if (len <= 0)
		return (src);
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = ft_strjoindel(tmp, "0");
		len--;
	}
	tmp = ft_strjoindel(tmp, src);
	ft_strdel(&src);
	return (tmp);
}

static int	get_len(char *src, t_opt opt, int type)
{
	int		len;

	len = opt.width - ft_strlen(src);
	if ((opt.flags & HASH) && (((type == HEX || type == MHEX)
					&& !ft_strequ(src, "0")) || type == POINT))
		len -= 2;
	if ((opt.flags & HASH) && type == OCT && !ft_strequ(src, "0"))
		len -= 1;
	if ((opt.flags & PLUS) || (opt.flags & SPACE))
		len -= 1;
	return (len);
}

char		*handle_width(char *src, t_opt *opt, int type)
{
	int		len;
	char	*tmp;

	len = get_len(src, *opt, type);
	if (len <= 0)
		return (handle_hash(src, opt, type));
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = (opt->zero && opt->preci == -1 && (opt->flags & MINUS) == 0) ?
			ft_strjoindel(tmp, "0") : ft_strjoindel(tmp, " ");
		len--;
	}
	if (!opt->zero || (opt->zero && opt->preci != -1))
		src = handle_hash(src, opt, type);
	if (opt->flags & MINUS)
		tmp = ft_strjoinddel(src, tmp);
	else
	{
		tmp = ft_strjoindel(tmp, src);
		ft_strdel(&src);
	}
	return (tmp);
}

char		*handle_number_flag(char *src, t_opt *opt, int type)
{
	src = handle_preci(src, opt->preci);
	src = handle_width(src, opt, type);
	src = handle_hash(src, opt, type);
	return (src);
}
