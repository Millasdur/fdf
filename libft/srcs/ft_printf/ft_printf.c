/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:29 by hlely             #+#    #+#             */
/*   Updated: 2018/04/21 17:53:45 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_function	g_function[] =
{
	{'s', &ft_string},
	{'p', &ft_pointer},
	{'c', &ft_char},
	{'C', &ft_char},
	{'d', &ft_int},
	{'D', &ft_maxiint},
	{'i', &ft_int},
	{'o', &ft_octal},
	{'O', &ft_maxioctal},
	{'x', &ft_minihexa},
	{'X', &ft_maxihexa},
	{'u', &ft_uint},
	{'U', &ft_umaxiint},
	{'%', &ft_percent},
	{0, NULL}
};

int			is_attr(char c)
{
	if (ft_strchr("0123456789.-+ #lhjz", c))
		return (1);
	return (0);
}

char		*ft_percent(va_list *arg, t_opt *opt)
{
	char	*res;

	(void)arg;
	res = ft_strdup("%");
	opt->preci = -1;
	res = handle_strflag(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}

char		*prepare_convertion(va_list *arg, char **str, t_opt *opt, char *res)
{
	int		j;
	char	*tmp;

	tmp = ft_strsub(*str, 0, opt->i);
	res = ft_strnjoinddel(res, tmp, opt->len, ft_strlen(tmp));
	opt->len += opt->i;
	*str += opt->i + 1;
	opt->i = 0;
	j = opt->i;
	while ((*str)[opt->i] && is_attr((*str)[opt->i]))
		(opt->i)++;
	tmp = convert(arg, (*str)[opt->i], *str + j, opt);
	res = ft_strnjoinddel(res, tmp, opt->len - opt->len2, opt->len2);
	*str += opt->i + 1;
	opt->i = 0;
	return (res);
}

int			ft_printf(char *str, ...)
{
	char	*res;
	va_list	arg;
	t_opt	opt;

	opt.i = 0;
	opt.len = 0;
	opt.len2 = 0;
	va_start(arg, str);
	res = ft_strdup("");
	while (str[opt.i])
	{
		if (str[opt.i] == '%')
			res = prepare_convertion(&arg, &str, &opt, res);
		else
			(opt.i)++;
	}
	va_end(arg);
	res = ft_strnjoindel(res, str, opt.len, ft_strlen(str));
	opt.len += ft_strlen(str);
	opt.len ? ft_putnstr(res, opt.len) : 0;
	ft_strdel(&res);
	return (opt.len);
}

int			ft_printf_fd(int fd, char *str, ...)
{
	char	*res;
	va_list	arg;
	t_opt	opt;

	opt.i = 0;
	opt.len = 0;
	va_start(arg, str);
	res = ft_strdup("");
	while (str[opt.i])
	{
		if (str[opt.i] == '%')
			res = prepare_convertion(&arg, &str, &opt, res);
		else
			(opt.i)++;
	}
	va_end(arg);
	res = ft_strnjoindel(res, str, opt.len, ft_strlen(str));
	opt.len += ft_strlen(str);
	opt.len ? write(fd, res, opt.len) : 0;
	ft_strdel(&res);
	return (opt.len);
}
