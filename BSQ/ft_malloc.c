/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:51:08 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 20:51:16 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		**arr_alloc(int y, int x)
{
	int **map;
	int *start;
	int i;

	i = 0;
	map = (int **)malloc(y * sizeof(int *) + y * x * sizeof(int));
	if (map == NULL)
		return (0);
	start = (int*)((char*)map + y * sizeof(int *));
	while (i < y)
	{
		map[i] = start + i * x;
		i++;
	}
	return (map);
}

void	arr_free(int **map)
{
	free(map);
}
