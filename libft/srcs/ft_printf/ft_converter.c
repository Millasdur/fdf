/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:09:26 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 14:35:02 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_converter(char c)
{
	int		j;

	j = 0;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
			return (1);
		j++;
	}
	return (0);
}

char		*convert(va_list *arg, char c, char *flags, t_opt *opt)
{
	int		j;
	int		len;

	j = 0;
	len = 0;
	opt->charac = c;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
		{
			get_attr(flags, opt);
			return (g_function[j].f(arg, opt));
		}
		j++;
	}
	get_attr(flags, opt);
	return (ft_else(arg, opt));
}
