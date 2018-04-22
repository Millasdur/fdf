/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:06:21 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 16:30:00 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_preci(char *str)
{
	int		i;
	int		preci;

	i = 0;
	preci = -1;
	while (str[i] && !is_converter(str[i]))
	{
		if (str[i] == '.')
		{
			i++;
			preci = ft_atoi(str + i);
			while (str[i] && str[i + 1] &&
					!is_converter(str[i + 1]) && ft_isdigit(str[i]))
				i++;
		}
		i++;
	}
	return (preci);
}

static int	get_width(char *str)
{
	int		i;
	int		width;

	i = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.'
			&& (!ft_isdigit(str[i]) || str[i] == '0'))
		i++;
	width = ft_atoi(str + i);
	return (width);
}

static int	get_zero(char *str)
{
	int		i;
	int		zero;

	i = 0;
	zero = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.'
			&& !ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '0')
		zero = 1;
	return (zero);
}

static int	get_modif(char *str)
{
	int		i;
	int		modif;

	i = 0;
	modif = 0;
	while (str[i] && !is_converter(str[i]))
	{
		if (ft_strchr("lhjz", str[i]))
		{
			if (str[i] == 'l' && str[i + 1] && str[i + 1] == 'l')
				modif = LL_MODE;
			else if (str[i] == 'l' && str[i + 1] && str[i + 1] != 'l')
				modif = L_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] == 'h')
				modif = HH_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] != 'h')
				modif = H_MODE;
			else if (str[i] == 'j')
				modif = J_MODE;
			else if (str[i] == 'z')
				modif = Z_MODE;
		}
		i += (modif == HH_MODE || modif == LL_MODE) ? 2 : 1;
	}
	return (modif);
}

void		get_attr(char *str, t_opt *opt)
{
	opt->width = get_width(str);
	opt->preci = get_preci(str);
	opt->zero = get_zero(str);
	opt->flags = get_flag(str);
	opt->modif = get_modif(str);
}
