/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:50:04 by wmelly            #+#    #+#             */
/*   Updated: 2020/09/09 20:49:00 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	skip_first(int fd)
{
	char	buf;

	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			return ;
	}
}

int		min(int a, int b, int c)
{
	if (a >= b && c >= b)
		return (b);
	else if (a <= b && a <= c)
		return (a);
	return (c);
}

int		numerize(t_list *params, int **map, int i, int j)
{
	if (i == 0 || j == 0)
	{
		if (params->buf[0] == params->emp)
			return (1);
		else if (params->buf[0] == params->obs)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (params->buf[0] == params->emp)
			return (1 + min(map[i - 1][j], map[i][j - 1], map[i - 1][j - 1]));
		else if (params->buf[0] == params->obs)
			return (0);
		else
			return (-1);
	}
}

int		fill_map(t_list *params, int **map, int fd)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i < (params->y) && j < ((params->x)))
	{
		j++;
		read(fd, params->buf, 1);
		if (params->buf[0] != '\n')
		{
			map[i][j] = numerize(params, map, i, j);
			checker(map, i, j, params);
			if (map[i][j] == -1)
				return (1);
			if (j == ((params->x) - 1))
			{
				i++;
				j = -1;
			}
		}
		else
			j = -1;
	}
	return (0);
}

void	checker(int **map, int i, int j, t_list *params)
{
	if (params->size < map[i][j])
	{
		params->size = map[i][j];
		params->column = j;
		params->line = i;
	}
}
