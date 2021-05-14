/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:15:16 by wmelly            #+#    #+#             */
/*   Updated: 2020/09/09 20:22:31 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	marker(int **map, int i, int j, t_list *params)
{
	int sz;
	int clmn;
	int ln;

	ln = params->line;
	clmn = params->column;
	sz = params->size;
	if ((j > (clmn - sz) && (j < (++clmn))) && (i > (ln - sz) && (i < (++ln))))
		ft_putchar(params->mark);
	else
	{
		if (map[i][j] == 0)
			ft_putchar(params->obs);
		else
			ft_putchar(params->emp);
	}
}

void	output(int **map, t_list *params)
{
	int i;
	int j;

	i = 0;
	while (i < params->y)
	{
		j = 0;
		while (j < params->x)
		{
			marker(map, i, j, params);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
