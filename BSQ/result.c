/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:42:13 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 19:54:31 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_list	*put_params(char *arr, int x, int y)
{
	int		i;
	t_list	*params;

	i = 0;
	while (arr[i])
		i++;
	params = ft_create_elem(x, y, arr[i - 3], arr[i - 2]);
	params->mark = arr[i - 1];
	params->line = 0;
	params->column = 0;
	params->size = 0;
	return (params);
}

void	creat_map(t_list *params, char *filename)
{
	int		**map;
	int		point;
	int		fd;

	map = arr_alloc(params->y, params->x);
	fd = open(filename, O_RDONLY);
	skip_first(fd);
	point = fill_map(params, map, fd);
	close(fd);
	if (point == 1)
		ft_putstr("map error\n");
	else
		output(map, params);
	arr_free(map);
}

void	bsq_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (check_file_map(filename, fd) == -1)
		ft_putstr("map error\n");
	else
		close(fd);
}

void	bsq_input(char *filename)
{
	int fd;

	fd = open(filename, O_RDWR);
	close(fd);
	if (fd == -1)
		ft_putstr("map error\n");
	else
		bsq_map(filename);
}
