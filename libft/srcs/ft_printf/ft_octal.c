/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:33:06 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 15:33:01 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_octal(va_list *arg, t_opt *opt)
{
	uintmax_t		nb;
	char			*res;

	nb = get_unumber(arg, *opt);
	opt->flags ^= (nb == 0 && opt->preci != 0) ? (opt->flags & HASH) : 0;
	res = ft_uitoa_base(nb, 8);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, opt, OCT);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}

char		*ft_maxioctal(va_list *arg, t_opt *opt)
{
	uintmax_t		nb;
	char			*res;

	opt->modif = L_MODE;
	nb = get_unumber(arg, *opt);
	opt->flags ^= (nb == 0 && opt->preci != 0) ? (opt->flags & HASH) : 0;
	res = ft_uitoa_base(nb, 8);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, opt, OCT);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
