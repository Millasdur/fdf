/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:26:19 by hlely             #+#    #+#             */
/*   Updated: 2018/04/21 15:55:22 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

		#include <stdio.h>

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define HASH		1
# define MINUS		2
# define PLUS		4
# define SPACE		8

# define J_MODE		1
# define Z_MODE		2
# define HH_MODE	4
# define H_MODE		8
# define L_MODE		16
# define LL_MODE	32
# define NONE		64

# define INT		1
# define OCT		2
# define HEX		3
# define MHEX		4
# define POINT		5

typedef struct		s_opt
{
	int		i;
	int		len;
	int		len2;
	int		positive;
	int		preci;
	int		width;
	int		modif;
	int		charac;
	int		zero;
	int		flags;
}					t_opt;

typedef struct		s_function
{
	char	value;
	char	*(*f)(va_list*, t_opt*);
}					t_function;

extern t_function	g_function[];

int					ft_printf(char *str, ...);
int					ft_printf_fd(int fd, char *str, ...);
char				*ft_string(va_list *arg, t_opt *opt);
char				*ft_pointer(va_list *arg, t_opt *opt);
char				*ft_char(va_list *arg, t_opt *opt);
char				*ft_wchar(va_list *arg, t_opt *opt);
char				*ft_percent(va_list *arg, t_opt *opt);
char				*ft_int(va_list *arg, t_opt *opt);
char				*ft_maxiint(va_list *arg, t_opt *opt);
char				*ft_uint(va_list *arg, t_opt *opt);
char				*ft_umaxiint(va_list *arg, t_opt *opt);
char				*ft_octal(va_list *arg, t_opt *opt);
char				*ft_maxioctal(va_list *arg, t_opt *opt);
char				*ft_minihexa(va_list *arg, t_opt *opt);
char				*ft_maxihexa(va_list *arg, t_opt *opt);
char				*ft_else(va_list *arg, t_opt *opt);

int					is_converter(char c);
char				*convert(va_list *arg, char c, char *flags, t_opt *opt);

void				get_attr(char *str, t_opt *opt);
int					get_flag(char *str);

char				*handle_number_flag(char *src, t_opt *opt, int type);
char				*handle_hash(char *src, t_opt *opt, int type);
char				*handle_plus_space(char *src, t_opt *opt, int type);

intmax_t			get_number(va_list *arg, t_opt opt);
uintmax_t			get_unumber(va_list *arg, t_opt opt);

char				*handle_strflag(char *src, t_opt opt);
char				*handle_charflag(char *src, t_opt opt, int len);
#endif
