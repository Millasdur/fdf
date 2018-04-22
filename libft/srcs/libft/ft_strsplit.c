/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:45:08 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 14:34:54 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	if (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			word++;
		i++;
	}
	return (word + 1);
}

static void	setres(char const *s, int var[2], int *j, char **res)
{
	int end;

	end = 0;
	while (s[(var)[0]] && s[(var[0])] == var[1])
		(var[0])++;
	end = var[0];
	while (s[end] && s[end] != var[1])
		end++;
	if (end - var[0] != 0)
		res[(*j)++] = ft_strsub(s, var[0], end - var[0]);
	var[0] = end;
}

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	char	**res;
	int		var[2];

	j = 0;
	var[0] = 0;
	var[1] = c;
	if (s && c)
	{
		if (!(res = (char**)malloc(sizeof(char*) * (length(s, c) + 1))))
			return (0);
		while (s[var[0]])
			setres(s, var, &j, res);
		res[j] = 0;
		return (res);
	}
	return (0);
}
