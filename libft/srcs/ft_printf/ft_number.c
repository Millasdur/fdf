/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:56:21 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 15:42:42 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_maxiint(va_list *arg, t_opt *opt)
{
	intmax_t			nb;
	char				*res;

	opt->modif = L_MODE;
	nb = get_number(arg, *opt);
	if (nb < 0)
	{
		opt->positive = 0;
		opt->flags |= PLUS;
		nb = -nb;
	}
	res = ft_itoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, opt, INT);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}

char		*ft_int(va_list *arg, t_opt *opt)
{
	intmax_t			nb;
	char				*res;

	nb = get_number(arg, *opt);
	if (nb < 0)
	{
		opt->positive = 0;
		opt->flags |= PLUS;
		nb = -nb;
	}
	res = ft_itoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, opt, INT);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}

char		*ft_minihexa(va_list *arg, t_opt *opt)
{
	uintmax_t	nb;
	char		*res;

	nb = get_unumber(arg, *opt);
	opt->flags ^= (nb == 0) ? (opt->flags & HASH) : 0;
	res = ft_uitoa_base(nb, 16);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	ft_lowercase(&res);
	res = handle_number_flag(res, opt, HEX);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}

char		*ft_maxihexa(va_list *arg, t_opt *opt)
{
	uintmax_t		nb;
	char			*res;

	nb = get_unumber(arg, *opt);
	opt->flags ^= (nb == 0) ? (opt->flags & HASH) : 0;
	res = ft_uitoa_base(nb, 16);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, opt, MHEX);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
