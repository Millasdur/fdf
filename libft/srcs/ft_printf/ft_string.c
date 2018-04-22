/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:35:25 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 13:54:22 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_string(va_list *arg, t_opt *opt)
{
	char	*res;

	res = va_arg(*arg, char*);
	if (res == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	res = handle_strflag(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
