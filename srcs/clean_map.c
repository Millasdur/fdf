/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:02:01 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 18:04:41 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		clean_map(t_data data, t_point ***point)
{
	int		i;

	i = 0;
	while (i < data.y)
	{
		free((*point)[i]);
		(*point)[i] = NULL;
		i++;
	}
	free(*point);
	*point = NULL;
	return (1);
}
