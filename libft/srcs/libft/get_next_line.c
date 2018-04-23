/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:19:22 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 11:53:36 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clear_buf(int fd, char buf[BUFF_SIZE], int *i)
{
	int j;

	j = 0;
	while (j < BUFF_SIZE)
	{
		buf[j] = '\0';
		j++;
	}
	*i = 0;
	return (read(fd, buf, BUFF_SIZE));
}

static char	*cpy_buf(char buf[BUFF_SIZE], char *str, int *i, int *ret)
{
	char *tmp;

	while (buf[*i] && buf[*i] != '\n')
	{
		str = ft_strncat(str, buf + *i, 1);
		(*i)++;
	}
	if (*i == BUFF_SIZE - 1)
	{
		*ret = 0;
		*i = 0;
	}
	else
		(*i)++;
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strnew(ft_strlen(tmp) + 1);
	str = ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (str);
}

char		*resize(char *str, char buf[BUFF_SIZE], int i)
{
	char	*tmp;
	int		len;

	str = ft_strncat(str, buf + i, BUFF_SIZE - i);
	len = ft_strlen(str);
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strnew(len + BUFF_SIZE);
	str = ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (str);
}

int			check_first(char **line, int fd, int *ret, int *i)
{
	if (line == 0 || fd < 0 || BUFF_SIZE <= 0)
	{
		*i = 0;
		*ret = 0;
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE];
	static int	ret = 0;
	static int	i = 0;

	if (!check_first(line, fd, &ret, &i))
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (fd == 0 && !buf[i])
		check_first(0, fd, &ret, &i);
	ret = (!ret) ? clear_buf(fd, buf, &i) : ret;
	if (ret < 0)
		return (check_first(0, fd, &ret, &i) - 1);
	while (ret == BUFF_SIZE && ft_strchr(buf + i, '\n') == NULL)
	{
		*line = resize(*line, buf, i);
		ret = clear_buf(fd, buf, &i);
		if (ret == 0)
			return (1);
	}
	if (ret == 0 || (!buf[i]))
		return ((check_first(0, fd, &ret, &i) == 1));
	*line = cpy_buf(buf, *line, &i, &ret);
	return (1);
}
