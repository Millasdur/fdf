/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:05:25 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 11:12:14 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	start;
	unsigned int	i;
	size_t			len;

	if (s)
	{
		i = 0;
		len = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		start = i;
		while (s[i])
		{
			if ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
				len = i;
			i++;
		}
		if (len == 0 && start > 0)
			return (ft_strdup("\0"));
		res = ft_strsub(s, start, len - start + 1);
		return (res);
	}
	return (NULL);
}
